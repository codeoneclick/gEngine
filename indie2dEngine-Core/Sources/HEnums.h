//
//  HEnums.h
//  indi2dEngine-Core
//
//  Created by Sergey Sergeev on 5/7/13.
//  Copyright (c) 2013 Sergey Sergeev. All rights reserved.
//

#ifndef HEnums_h
#define HEnums_h

enum E_PLATFORM_API
{
    E_PLATFORM_API_IOS = 0,
    E_PLATFORM_API_WIN32,
    E_PLATFORM_API_OSX,
    E_PLATFORM_API_NDK
};

enum E_RESOURCE_CLASS
{
    E_RESOURCE_CLASS_UNKNOWN = 0,
    E_RESOURCE_CLASS_TEXTURE,
    E_RESOURCE_CLASS_SHADER,
    E_RESOURCE_CLASS_MESH,
    E_RESOURCE_CLASS_SKELETON,
    E_RESOURCE_CLASS_SEQUENCE,
    E_RESOURCE_CLASS_MATERIAL,
    E_RESOURCE_CLASS_MAX
};

enum E_TEMPLATE_LOADERS
{
    E_TEMPLATE_LOADERS_UNKNOWN = 0,
    E_TEMPLATE_LOADERS_MODEL,
    E_TEMPLATE_LOADERS_OCEAN,
    E_TEMPLATE_LOADERS_LANDSCAPE,
    E_TEMPLATE_LOADERS_PARTICLE_EMITTER,
    E_TEMPLATE_LOADERS_GAME_TRANSITIONS,
	E_TEMPLATE_LOADERS_GUI,
    E_TEMPLATE_LOADERS_MAX
};

enum E_SHADER_ATTRIBUTE
{
    E_SHADER_ATTRIBUTE_POSITION = 0,
    E_SHADER_ATTRIBUTE_TEXCOORD,
    E_SHADER_ATTRIBUTE_NORMAL,
    E_SHADER_ATTRIBUTE_TANGENT,
    E_SHADER_ATTRIBUTE_COLOR,
    E_SHADER_ATTRIBUTE_EXTRA,
    E_SHADER_ATTRIBUTE_MAX
};

enum E_SHADER_UNIFORM
{
    E_SHADER_UNIFORM_MATRIX_WORLD = 0,
    E_SHADER_UNIFORM_MATRIX_VIEW,
    E_SHADER_UNIFORM_MATRIX_PROJECTION,
    E_SHADER_UNIFORM_MATRIX_NORMAL,
    E_SHADER_UNIFORM_MATRIX_BONES,
    E_SHADER_UNIFORM_VECTOR_CAMERA_POSITION,
    E_SHADER_UNIFORM_VECTOR_LIGHT_01_POSITION,
    E_SHADER_UNIFORM_VECTOR_LIGHT_02_POSITION,
    E_SHADER_UNIFORM_VECTOR_LIGHT_03_POSITION,
    E_SHADER_UNIFORM_VECTOR_LIGHT_04_POSITION,
    E_SHADER_UNIFORM_VECTOR_LIGHT_01_COLOR,
    E_SHADER_UNIFORM_VECTOR_LIGHT_02_COLOR,
    E_SHADER_UNIFORM_VECTOR_LIGHT_03_COLOR,
    E_SHADER_UNIFORM_VECTOR_LIGHT_04_COLOR,
    E_SHADER_UNIFORM_VECTOR_CLIP_PLANE,
    E_SHADER_UNIFORM_FLOAT_CAMERA_NEAR,
    E_SHADER_UNIFORM_FLOAT_CAMERA_FAR,
    E_SHADER_UNIFORM_FLOAT_TIMER,
    E_SHADER_UNIFORM_INT_LIGHTS_COUNT,
    E_SHADER_UNIFORM_INT_FLAG_01,
    E_SHADER_UNIFORM_INT_FLAG_02,
    E_SHADER_UNIFORM_INT_FLAG_03,
    E_SHADER_UNIFORM_INT_FLAG_04,
    E_SHADER_UNIFORM_MAX
};

enum E_SHADER_SAMPLER
{
    E_SHADER_SAMPLER_01 = 0,
    E_SHADER_SAMPLER_02,
    E_SHADER_SAMPLER_03,
    E_SHADER_SAMPLER_04,
    E_SHADER_SAMPLER_05,
    E_SHADER_SAMPLER_06,
    E_SHADER_SAMPLER_07,
    E_SHADER_SAMPLER_08,
    E_SHADER_SAMPLER_MAX
};

enum E_SERIALIZER_STATUS
{
    E_SERIALIZER_STATUS_UNKNOWN = 0,
    E_SERIALIZER_STATUS_INPROGRESS,
    E_SERIALIZER_STATUS_FAILURE,
    E_SERIALIZER_STATUS_SUCCESS
};

enum E_COMMITER_STATUS
{
    E_COMMITER_STATUS_UNKNOWN = 0,
    E_COMMITER_STATUS_INPROGRESS,
    E_COMMITER_STATUS_FAILURE,
    E_COMMITER_STATUS_SUCCESS
};

enum E_RESOURCE_LOADING_OPERATION_STATUS
{
    E_RESOURCE_LOADING_OPERATION_STATUS_UNKNOWN = 0,
    E_RESOURCE_LOADING_OPERATION_STATUS_INPROGRESS,
    E_RESOURCE_LOADING_OPERATION_STATUS_WAITING,
    E_RESOURCE_LOADING_OPERATION_STATUS_FAILURE,
    E_RESOURCE_LOADING_OPERATION_STATUS_SUCCESS
};

enum E_TEMPLATE_LOADING_OPERATION_STATUS
{
    E_TEMPLATE_LOADING_OPERATION_STATUS_UNKNOWN = 0,
    E_TEMPLATE_LOADING_OPERATION_STATUS_INPROGRESS,
    E_TEMPLATE_LOADING_OPERATION_STATUS_WAITING,
    E_TEMPLATE_LOADING_OPERATION_STATUS_FAILURE,
    E_TEMPLATE_LOADING_OPERATION_STATUS_SUCCESS
};

enum E_RENDER_STATE
{
    E_RENDER_STATE_CULL_MODE = 0,
    E_RENDER_STATE_BLEND_MODE,
    E_RENDER_STATE_DEPTH_TEST,
    E_RENDER_STATE_DEPTH_MASK,
    E_RENDER_STATE_MAX
};

enum E_FRUSTUM_BOUND_RESULT
{
    E_FRUSTUM_BOUND_RESULT_OUTSIDE = 0,
    E_FRUSTUM_BOUND_RESULT_INTERSECT,
    E_FRUSTUM_BOUND_RESULT_INSIDE
};

enum E_FRUSTUM_PLANE
{
    E_FRUSTUM_PLANE_TOP = 0,
    E_FRUSTUM_PLANE_BOTTOM,
    E_FRUSTUM_PLANE_LEFT,
    E_FRUSTUM_PLANE_RIGHT,
    E_FRUSTUM_PLANE_NEAR,
    E_FRUSTUM_PLANE_FAR,
    E_FRUSTUM_PLANE_MAX
};

enum E_LOADING_STATUS
{
    E_LOADING_STATUS_UNLOADED = 1,
    E_LOADING_STATUS_TEMPLATE_LOADED = 2,
    E_LOADING_STATUS_SHADER_LOADED = 4,
    E_LOADING_STATUS_MESH_LOADED = 8,
    E_LOADING_STATUS_SKELETON_LOADED = 16,
    E_LOADING_STATUS_SEQUENCE_LOADED = 32,
};

enum E_LOADING_CALLBACK
{
    E_LOADING_CALLBACK_MATERIAL = 0,
    E_LOADING_CALLBACK_SHADER,
    E_LOADING_CALLBACK_MESH,
    E_LOADING_CALLBACK_SKELETON,
    E_LOADING_CALLBACK_SEQUENCE,
    E_LOADING_CALLBACK_TEXTURE
};

enum E_RESOURCE_STATUS
{
    E_RESOURCE_STATUS_UNLOADED = 1,
    E_RESOURCE_STATUS_LOADED = 2,
    E_RESOURCE_STATUS_COMMITED = 4
};

enum E_RESOURCE_DATA_STATUS
{
    E_RESOURCE_DATA_STATUS_STARTED = 0,
    E_RESOURCE_DATA_STATUS_PROGRESS,
    E_RESOURCE_DATA_STATUS_FINISHED
};

enum E_UNIFORM_CLASS
{
    E_UNIFORM_CLASS_MAT3X3 = 0,
    E_UNIFORM_CLASS_MAT4X4,
    E_UNIFORM_CLASS_VECTOR2,
    E_UNIFORM_CLASS_VECTOR3,
    E_UNIFORM_CLASS_VECTOR4,
    E_UNIFORM_CLASS_FLOAT,
    E_UNIFORM_CLASS_INT,
    E_UNIFORM_CLASS_SAMPLER
};

enum E_LIGHTS
{
    E_LIGHT_01 = 0,
    E_LIGHT_02,
    E_LIGHT_03,
    E_LIGHT_04,
    E_LIGHT_MAX
};

enum E_GUI_LOADING_SCHEME
{
	E_GUI_LOADING_SCHEME_NONE = 0,
	E_GUI_LOADING_SCHEME_CONTAINER,
	E_GUI_LOADING_SCHEME_BUTTON
};

enum E_BATCH_GEOMETRY_MODE
{
	E_BATCH_GEOMETRY_MODE_NONE = 0,
	E_BATCH_GEOMETRY_MODE_MODELS,
	E_BATCH_GEOMETRY_MODE_CONTROLS,
	E_BATCH_GEOMETRY_MODE_PARTICLES
};

enum E_TEMPLATE_META_TYPE
{
    E_TEMPLATE_META_TYPE_BOOL = 0,
    E_TEMPLATE_META_TYPE_I8,
    E_TEMPLATE_META_TYPE_UI8,
    E_TEMPLATE_META_TYPE_I16,
    E_TEMPLATE_META_TYPE_UI16,
    E_TEMPLATE_META_TYPE_I32,
    E_TEMPLATE_META_TYPE_UI32,
    E_TEMPLATE_META_TYPE_F32,
    E_TEMPLATE_META_TYPE_STRING
};

enum E_RESOURCE_LOADER
{
    E_RESOURCE_LOADER_TEXTURE = 0,
    E_RESOURCE_LOADER_SHADER,
    E_RESOURCE_LOADER_MESH,
    E_RESOURCE_LOADER_MAX
};

#endif
