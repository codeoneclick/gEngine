//
//  CFrustum.cpp
//  indie2dEngine
//
//  Created by Sergey Sergeev on 5/24/13.
//  Copyright (c) 2013 Sergey Sergeev. All rights reserved.
//

#include "CFrustum.h"
#include "CCamera.h"

CFrustum::CFrustum(CCamera* _camera) :
m_camera(_camera)
{

}

CFrustum::~CFrustum(void)
{

}

glm::vec4 CFrustum::_CreatePlane(const glm::vec3 &_point_01, const glm::vec3 &_point_02, const glm::vec3 &_point_03)
{
    glm::vec3 edge_01, edge_02;
	edge_01 = _point_01 - _point_02;
	edge_02 = _point_03 - _point_02;
    glm::vec3 normal = glm::normalize(glm::cross(edge_01, edge_02));
	f32 offset = -glm::dot(normal, _point_02);
    return glm::vec4(normal, offset);
}

inline f32 CFrustum::getDistanceToPlane(const glm::vec4& plane, const glm::vec3& point)
{
    static glm::vec3 abc = glm::vec3(0.0);
    abc = CFrustum::getPlaneABC(plane);
    static f32 d = 0.0;
    d = CFrustum::getPlaneD(plane);
    return (d + glm::dot(abc, point)) * -1.0;
}

inline glm::vec3 CFrustum::getPlaneABC(const glm::vec4& plane)
{
    return glm::vec3(plane.x, plane.y, plane.z);
}

inline f32 CFrustum::getPlaneD(const glm::vec4& plane)
{
    return plane.w;
}

void CFrustum::Update(void)
{
    f32 tan = tanf(glm::radians(m_camera->Get_Fov() * 0.5));
	f32 nearHeight = m_camera->Get_Near() * tan;
	f32 nearWidth = nearHeight * m_camera->Get_Aspect();
	f32 farHeight = m_camera->Get_Far()  * tan;
	f32 farWidth = farHeight * m_camera->Get_Aspect();
    
    glm::vec3 basis_Z = glm::normalize(m_camera->Get_Position() - m_camera->Get_LookAt());
    glm::vec3 basis_X = glm::normalize(glm::cross(m_camera->Get_Up(), basis_Z));
    glm::vec3 basis_Y = glm::cross(basis_Z, basis_X);
    
    glm::vec3 nearOffset = m_camera->Get_Position() - basis_Z * m_camera->Get_Near();
	glm::vec3 farOffset = m_camera->Get_Position() - basis_Z * m_camera->Get_Far();
    
	glm::vec3 nearTopLeftPoint = nearOffset + basis_Y * nearHeight - basis_X * nearWidth;
	glm::vec3 nearTopRightPoint = nearOffset + basis_Y * nearHeight + basis_X * nearWidth;
	glm::vec3 nearBottomLeftPoint = nearOffset - basis_Y * nearHeight - basis_X * nearWidth;
	glm::vec3 nearBottomRightPoint = nearOffset - basis_Y * nearHeight + basis_X * nearWidth;
    
	glm::vec3 farTopLeftPoint = farOffset + basis_Y * farHeight - basis_X * farWidth;
	glm::vec3 farTopRightPoint = farOffset + basis_Y * farHeight + basis_X * farWidth;
	glm::vec3 farBottomLeftPoint = farOffset - basis_Y * farHeight - basis_X * farWidth;
	glm::vec3 farBottomRightPoint = farOffset - basis_Y * farHeight + basis_X * farWidth;
    
	m_planes[E_FRUSTUM_PLANE_TOP] = CFrustum::_CreatePlane(nearTopRightPoint, nearTopLeftPoint, farTopLeftPoint);
	m_planes[E_FRUSTUM_PLANE_BOTTOM] = CFrustum::_CreatePlane(nearBottomLeftPoint, nearBottomRightPoint, farBottomRightPoint);
	m_planes[E_FRUSTUM_PLANE_LEFT] = CFrustum::_CreatePlane(nearTopLeftPoint, nearBottomLeftPoint, farBottomLeftPoint);
	m_planes[E_FRUSTUM_PLANE_RIGHT] = CFrustum::_CreatePlane(nearBottomRightPoint, nearTopRightPoint, farBottomRightPoint);
	m_planes[E_FRUSTUM_PLANE_NEAR] = CFrustum::_CreatePlane(nearTopLeftPoint, nearTopRightPoint, nearBottomRightPoint);
	m_planes[E_FRUSTUM_PLANE_FAR] = CFrustum::_CreatePlane(farTopRightPoint, farTopLeftPoint, farBottomLeftPoint);
}

E_FRUSTUM_BOUND_RESULT CFrustum::IsPointInFrustum(const glm::vec3& _point)
{
    for(ui32 i = 0; i < E_FRUSTUM_PLANE_MAX; ++i)
    {
        if(CFrustum::getDistanceToPlane(m_planes[i], _point) < 0.0f)
        {
			return E_FRUSTUM_BOUND_RESULT_OUTSIDE;
        }
	}
	return E_FRUSTUM_BOUND_RESULT_INSIDE;
}

E_FRUSTUM_BOUND_RESULT CFrustum::IsSphereInFrumstum(const glm::vec3& _center, f32 _radius)
{
    E_FRUSTUM_BOUND_RESULT result = E_FRUSTUM_BOUND_RESULT_INSIDE;
	for(ui32 i = 0; i < E_FRUSTUM_PLANE_MAX; ++i)
    {
		f32 distance = CFrustum::getDistanceToPlane(m_planes[i], _center);
		if (distance < -_radius)
        {
			return E_FRUSTUM_BOUND_RESULT_OUTSIDE;
        }
		else if (distance < _radius)
        {
			result =  E_FRUSTUM_BOUND_RESULT_INTERSECT;
        }
	}
	return result;
}

#define kMaxPointsInBoundingBox 8

E_FRUSTUM_BOUND_RESULT CFrustum::IsBoundBoxInFrustum(const glm::vec3& maxBound,
                                                     const glm::vec3& minBound)
{
    glm::vec3 points[kMaxPointsInBoundingBox];
    points[0] = minBound;
    points[1] = glm::vec3(minBound.x, minBound.y, maxBound.z);
    points[2] = glm::vec3(maxBound.x, minBound.y, minBound.z);
    points[3] = glm::vec3(maxBound.x, minBound.y, maxBound.z);
    
    points[4] = maxBound;
    points[5] = glm::vec3(maxBound.x, maxBound.y, minBound.z);
    points[6] = glm::vec3(minBound.x, maxBound.y, maxBound.z);
    points[7] = glm::vec3(minBound.x, maxBound.y, minBound.z);
    
    E_FRUSTUM_BOUND_RESULT result = E_FRUSTUM_BOUND_RESULT_INSIDE;
    ui32 pointsIn, pointsOut;
    
    for(ui32 i = 0; i < E_FRUSTUM_PLANE_MAX; ++i)
    {
        pointsIn = 0;
        pointsOut = 0;
        for (ui32 j = 0; j < kMaxPointsInBoundingBox && (pointsIn == 0 || pointsOut == 0); ++j)
        {
            CFrustum::getDistanceToPlane(m_planes[i], points[j]) < 0.0 ? ++pointsOut : ++pointsIn;
        }
        if (!pointsIn)
        {
            result = E_FRUSTUM_BOUND_RESULT_OUTSIDE;
            break;
        }
        else if (pointsOut)
        {
            result = E_FRUSTUM_BOUND_RESULT_INTERSECT;
        }
    }
    return result;
}