//
//  CHeightmapProcessor.cpp
//  iGaia
//
//  Created by Sergey Sergeev on 3/3/13.
//
//

#include "CHeightmapProcessor.h"
#include "CTexture.h"
#include "CMaterial.h"
#include "CMesh.h"
#include "CVertexBuffer.h"
#include "CIndexBuffer.h"
#include "IScreenSpaceTextureAccessor.h"
#include "CConfigurationGameObjects.h"

#if defined(__IOS__)

#import <UIKit/UIKit.h>

#elif defined(__OSX__)

#include <Cocoa/Cocoa.h>

#endif

CHeightmapData::CHeightmapData(const std::string& filename) :
m_maxAltitude(-FLT_MAX),
m_maxHeight(-FLT_MAX),
m_minHeight(FLT_MAX)
{
    ui8* data = nullptr;
#if defined(__IOS__)
    
    UIImage* image = [UIImage imageNamed:[NSString stringWithCString:"mesa_heightmap" encoding:NSUTF8StringEncoding]];
    CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
    size_t bytesPerRow = image.size.width * 4;
    data = (ui8 *)malloc(image.size.height * bytesPerRow);
    CGContextRef context = CGBitmapContextCreate(data,
                                                 image.size.width,
                                                 image.size.height,
                                                 8,
                                                 bytesPerRow,
                                                 colorSpace,
                                                 kCGImageAlphaNoneSkipFirst);
    UIGraphicsPushContext(context);
    CGContextTranslateCTM(context, 0.0, image.size.height);
    CGContextScaleCTM(context, 1.0, -1.0);
    [image drawInRect:CGRectMake(0.0, 0.0, image.size.width, image.size.height)];
    UIGraphicsPopContext();
    
    m_sizeX = image.size.width;
    m_sizeZ = image.size.height;

#elif defined(__OSX__)
    
    NSImage* image = [NSImage imageNamed:[NSString stringWithCString:"mesa_heightmap" encoding:NSUTF8StringEncoding]];
    CGImageSourceRef source = CGImageSourceCreateWithData((__bridge CFDataRef)[image TIFFRepresentation], NULL);
    CGImageRef mask =  CGImageSourceCreateImageAtIndex(source, 0, NULL);
    NSBitmapImageRep *bitmap = [[NSBitmapImageRep alloc] initWithCGImage:mask];
    data = [bitmap bitmapData];
    
    m_sizeX = image.size.width;
    m_sizeZ = image.size.height;
    
#endif
    
    m_uncopressedVertexes.resize(m_sizeX * m_sizeZ);
    m_faces.resize((m_sizeX - 1) * (m_sizeZ - 1) * 2);
    
    for(ui32 i = 0; i < m_sizeX; ++i)
    {
        for(ui32 j = 0; j < m_sizeZ; ++j)
        {
            m_uncopressedVertexes[i + j * m_sizeZ].m_position = glm::vec3(static_cast<f32>(i),
                                                                          (static_cast<f32>(data[(i + j * m_sizeZ) * 4] - 64) / 255) * 32.0,
                                                                          static_cast<f32>(j));
            m_uncopressedVertexes[i + j * m_sizeZ].m_texcoord = CVertexBuffer::compressVec2(glm::vec2(static_cast<ui32>(i) /
                                                                                                      static_cast<f32>(m_sizeX),
                                                                                                      static_cast<ui32>(j) /
                                                                                                      static_cast<f32>(m_sizeZ)));
            if(fabsf(data[i +j * m_sizeZ]) > m_maxAltitude)
            {
                m_maxAltitude = fabsf(data[i +j * m_sizeZ]);
            }
            m_maxHeight = m_maxHeight < data[i + j * m_sizeZ] ? data[i + j * m_sizeZ] : m_maxHeight;
            m_minHeight = m_minHeight > data[i + j * m_sizeZ] ? data[i + j * m_sizeZ] : m_minHeight;
        }
    }

    ui32 index = 0;
    for(ui32 i = 0; i < (m_sizeX - 1); ++i)
    {
        for(ui32 j = 0; j < (m_sizeZ - 1); ++j)
        {
            SFace face;
            face.m_indexes[0] = i + j * m_sizeZ;
            m_uncopressedVertexes[face.m_indexes[0]].m_containInFace.push_back(index);
            glm::vec3 point_01 = m_uncopressedVertexes[face.m_indexes[0]].m_position;
            face.m_indexes[1] = i + (j + 1) * m_sizeZ;
            m_uncopressedVertexes[face.m_indexes[1]].m_containInFace.push_back(index);
            glm::vec3 point_02 = m_uncopressedVertexes[face.m_indexes[1]].m_position;
            face.m_indexes[2] = i + 1 + j * m_sizeZ;
            m_uncopressedVertexes[face.m_indexes[2]].m_containInFace.push_back(index);
            glm::vec3 point_03 = m_uncopressedVertexes[face.m_indexes[2]].m_position;
            
            glm::vec3 edge_01 = point_02 - point_01;
            glm::vec3 edge_02 = point_03 - point_01;
            glm::vec3 normal = glm::cross(edge_01, edge_02);
            f32 sin = glm::length(normal) / (glm::length(edge_01) * glm::length(edge_02));
            normal = glm::normalize(normal) * asinf(sin);
            glm::u8vec4 compressedNormal = CVertexBuffer::compressVec3(normal);
            face.m_normal = compressedNormal;
            
            m_faces[index] = face;
            index++;
            
            face.m_indexes[0] = i + (j + 1) * m_sizeZ;
            m_uncopressedVertexes[face.m_indexes[0]].m_containInFace.push_back(index);
            point_01 = m_uncopressedVertexes[face.m_indexes[0]].m_position;
            face.m_indexes[1] = i + 1 + (j + 1) * m_sizeZ;
            m_uncopressedVertexes[face.m_indexes[1]].m_containInFace.push_back(index);
            point_02 = m_uncopressedVertexes[face.m_indexes[1]].m_position;
            face.m_indexes[2] = i + 1 + j * m_sizeZ;
            m_uncopressedVertexes[face.m_indexes[2]].m_containInFace.push_back(index);
            point_03 = m_uncopressedVertexes[face.m_indexes[2]].m_position;
            
            edge_01 = point_02 - point_01;
            edge_02 = point_03 - point_01;
            normal = glm::cross(edge_01, edge_02);
            sin = glm::length(normal) / (glm::length(edge_01) * glm::length(edge_02));
            normal = glm::normalize(normal) * asinf(sin);
            compressedNormal = CVertexBuffer::compressVec3(normal);
            face.m_normal = compressedNormal;
            
            m_faces[index] = face;
            index++;
        }
    }
    
    for(ui32 i = 0; i < m_uncopressedVertexes.size(); ++i)
    {
        SUncomressedVertex vertex = m_uncopressedVertexes.at(i);
        assert(vertex.m_containInFace.size() != 0);
        glm::vec3 normal = CVertexBuffer::uncompressU8Vec4(m_faces.at(vertex.m_containInFace.at(0)).m_normal);
        for(ui32 j = 1; j < vertex.m_containInFace.size(); ++j)
        {
            normal += CVertexBuffer::uncompressU8Vec4(m_faces.at(vertex.m_containInFace.at(j)).m_normal);
        }
        normal = glm::normalize(normal);
        m_uncopressedVertexes.at(i).m_normal = CVertexBuffer::compressVec3(normal);
    }
    std::vector<SFace> facesDeleter;
    m_faces.swap(facesDeleter);
    
    for(ui32 i = 0; i < m_uncopressedVertexes.size(); ++i)
    {
        SCompressedVertex vertex;
        vertex.m_position = m_uncopressedVertexes.at(i).m_position;
        vertex.m_normal = m_uncopressedVertexes.at(i).m_normal;
        vertex.m_texcoord = m_uncopressedVertexes.at(i).m_texcoord;
        m_compressedVertexes.push_back(vertex);
    }
    std::vector<SUncomressedVertex> uncompressedVertexesDeleter;
    m_uncopressedVertexes.swap(uncompressedVertexesDeleter);
}

glm::vec3 CHeightmapData::getVertexPosition(ui32 i, ui32 j) const
{
    return m_compressedVertexes[i + j * m_sizeZ].m_position;
}

glm::u16vec2 CHeightmapData::getVertexTexcoord(ui32 i, ui32 j) const
{
    return m_compressedVertexes[i + j * m_sizeZ].m_texcoord;
}

glm::u8vec4 CHeightmapData::getVertexNormal(ui32 i, ui32 j) const
{
    return m_compressedVertexes[i + j * m_sizeZ].m_normal;
}

ui32 CHeightmapData::getSizeX(void) const
{
    return m_sizeX;
}

ui32 CHeightmapData::getSizeZ(void) const
{
    return m_sizeZ;
}

f32 CHeightmapData::getMaxAltitude(void) const
{
    return m_maxAltitude;
}

f32 CHeightmapData::getMaxHeight(void) const
{
    return m_maxHeight;
}

f32 CHeightmapData::getMinHeight(void) const
{
    return m_minHeight;
}

f32 CHeightmapDataAccessor::getAngleOnHeightmapSuface(const glm::vec3& point_01,
                                                      const glm::vec3& point_02,
                                                      const glm::vec3& point_03)
{
    f32 vectorLength_01 = sqrtf(powf(point_02.x - point_01.x, 2) + powf(point_02.y - point_01.y, 2) + powf(point_02.z - point_01.z, 2));
    f32 vectorLength_02 = sqrtf(powf(point_03.x - point_01.x, 2) + powf(point_03.y - point_01.y, 2) + powf(point_03.z - point_01.z, 2));
    
    f32 scalar = (point_02.x - point_01.x) * (point_03.x - point_01.x) +
    (point_02.y - point_01.y) * (point_03.y - point_01.y) +
    (point_02.z - point_01.z) * (point_03.z - point_01.z);
    return scalar / (vectorLength_01 * vectorLength_02);
}

f32 CHeightmapDataAccessor::getHeight(CSharedHeightmapDataRef data, const glm::vec3& position)
{
    f32 _x = position.x / 1.0;
    f32 _z = position.z / 1.0;
    i32 x = static_cast<i32>(floor(_x));
    i32 z = static_cast<i32>(floor(_z));
    f32 dx = _x - x;
    f32 dy = _z - z;
    
    if((x < 0) || (z < 0) || (x > (data->getSizeX() - 1)) || (z > (data->getSizeZ() - 1)))
    {
        return -0.0;
    }
    
    f32 height_00 = data->getVertexPosition(x, z).y;
    f32 height_01 = data->getVertexPosition(x, z).y;
    if(z < (data->getSizeZ() - 1) && z >= 0)
    {
        height_01 = data->getVertexPosition(x, z + 1).y;
    }
    
    f32 height_10 = data->getVertexPosition(x, z).y;
    if(x < (data->getSizeX() - 1) && x >= 0)
    {
        height_10 = data->getVertexPosition(x + 1, z).y;
    }
    
    f32 height_11 = data->getVertexPosition(x, z).y;
    if(z < (data->getSizeZ() - 1) && z >= 0 && x < (data->getSizeX() - 1) && x >= 0)
    {
        height_11 =  data->getVertexPosition(x + 1, z + 1).y;
    }
    
    f32 height_0 = height_00 * (1.0f - dy) + height_01 * dy;
    f32 height_1 = height_10 * (1.0f - dy) + height_11 * dy;
    return height_0 * (1.0f - dx) + height_1 * dx;
}

glm::vec2 CHeightmapDataAccessor::getAngleOnHeightmapSuface(CSharedHeightmapDataRef data, const glm::vec3& position)
{
    f32 offset = 0.25;
    glm::vec3 point_01 = position;
    glm::vec3 point_02 = glm::vec3(position.x, position.y + offset, position.z);
    f32 height =  CHeightmapDataAccessor::getHeight(data, glm::vec3(position.x + offset, 0.0f, position.z));
    glm::vec3 point_03 = glm::vec3(position.x + offset, height, position.z);
    height = CHeightmapDataAccessor::getHeight(data, glm::vec3(position.x, 0.0f, position.z + offset));
    glm::vec3 point_04 = glm::vec3(position.x, height, position.z + offset);
    
    f32 angle_01 = CHeightmapDataAccessor::getAngleOnHeightmapSuface(point_01, point_02, point_03);
    f32 angle_02 = CHeightmapDataAccessor::getAngleOnHeightmapSuface(point_01, point_02, point_04);
    
    return glm::vec2(-(-acosf(angle_02) + M_PI_2), -acosf(angle_01) + M_PI_2);
}

CHeightmapProcessingOperation::CHeightmapProcessingOperation(CSharedHeightmapDataRef heightmapData,
                                                             CSharedVertexBufferRef vertexBuffer,
                                                             CSharedIndexBufferRef indexBuffer,
                                                             ui32 indexX,
                                                             ui32 indexZ) :
m_heightmapData(heightmapData),
m_vertexBuffer(vertexBuffer),
m_indexBuffer(indexBuffer),
m_isRunning(false),
m_isCanceled(false),
m_isBackgroundThreadOperationDone(false),
m_isMainThreadOperationDone(false),
m_indexX(indexX),
m_indexZ(indexZ)
{

}

CHeightmapProcessingOperation::~CHeightmapProcessingOperation(void)
{
    
}

void CHeightmapProcessingOperation::executeBackgroundThreadOperation(void)
{
    assert(m_vertexBuffer != nullptr);
    assert(m_indexBuffer != nullptr);
    m_isRunning = true;
    m_currentExecutedFunction = std::async(std::launch::async, [this](){
        CHeightmapProcessor::generateTangentSpace(m_heightmapData,
                                                  m_vertexBuffer,
                                                  m_indexBuffer);
        m_isBackgroundThreadOperationDone = true;
    });
}

void CHeightmapProcessingOperation::executeMainThreadOperation(void)
{
    assert(m_vertexBuffer != nullptr);
    assert(m_indexBuffer != nullptr);
    
    m_vertexBuffer->unlock();
    m_isMainThreadOperationDone = true;
}

void CHeightmapProcessingOperation::cancel(void)
{
    m_isCanceled = true;
    m_isRunning = false;
}

bool CHeightmapProcessingOperation::isRunning(void) const
{
    return m_isRunning;
}

bool CHeightmapProcessingOperation::isCanceled(void) const
{
    return m_isCanceled;
}

bool CHeightmapProcessingOperation::isBackgroundThreadOperationDone(void) const
{
    return m_isBackgroundThreadOperationDone;
}

bool CHeightmapProcessingOperation::isMainThreadOperationDone(void) const
{
    return m_isMainThreadOperationDone;
}

ui32 CHeightmapProcessingOperation::getIndexX(void) const
{
    return m_indexX;
}

ui32 CHeightmapProcessingOperation::getIndexZ(void) const
{
    return m_indexZ;
}

CHeightmapProcessor::CHeightmapProcessor(const std::shared_ptr<IScreenSpaceTextureAccessor>& screenSpaceTextureAccessor,
                                         ISharedConfigurationRef configuration) :
m_heightmapData(nullptr),
m_screenSpaceTextureAccessor(screenSpaceTextureAccessor),
m_heightmapTexture(nullptr),
m_splattingTexture(nullptr),
m_diffuseTexture(nullptr),
m_normalTexture(nullptr),
m_edgesMaskTexture(nullptr)
{
    assert(m_screenSpaceTextureAccessor != nullptr);
    assert(configuration != nullptr);
    
    std::shared_ptr<CConfigurationLandscape> landscapeConfiguration = std::static_pointer_cast<CConfigurationLandscape>(configuration);
    m_heightmapData = std::make_shared<CHeightmapData>("");
    
    m_chunkSizeX = 64;
    m_chunkSizeZ = 64;
    
    m_numChunksX = m_heightmapData->getSizeX() / m_chunkSizeX;
    m_numChunksZ = m_heightmapData->getSizeZ() / m_chunkSizeZ;
    
    m_chunkSizeX++;
    m_chunkSizeZ++;
    
    m_chunksBounds.resize(m_numChunksX * m_numChunksZ);
    for(ui32 i = 0; i < m_numChunksX; ++i)
    {
        for(ui32 j = 0; j < m_numChunksZ; ++j)
        {
            glm::vec3 maxBound = glm::vec3( -4096.0f, -4096.0f, -4096.0f );
            glm::vec3 minBound = glm::vec3(  4096.0f,  4096.0f,  4096.0f );
            CHeightmapProcessor::createChunkBound(i, j, &maxBound, &minBound);
            m_chunksBounds[i + j * m_numChunksZ] = std::make_tuple(maxBound, minBound);
        }
    }
}

CHeightmapProcessor::~CHeightmapProcessor(void)
{
    
}

ui32 CHeightmapProcessor::getSizeX(void) const
{
    assert(m_heightmapData != nullptr);
    return m_heightmapData->getSizeX();
}

ui32 CHeightmapProcessor::getSizeZ(void) const
{
    assert(m_heightmapData != nullptr);
    return m_heightmapData->getSizeZ();
}

ui32 CHeightmapProcessor::getNumChunksX(void) const
{
    return m_numChunksX;
}

ui32 CHeightmapProcessor::getNumChunksZ(void) const
{
    return m_numChunksZ;
}

ui32 CHeightmapProcessor::getChunkSizeX(void) const
{
    return m_chunkSizeX;
}

ui32 CHeightmapProcessor::getChunkSizeZ(void) const
{
    return m_chunkSizeZ;
}

ui32 CHeightmapProcessor::createTextureId(void)
{
    ui32 textureId;
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    return textureId;
}

std::shared_ptr<CTexture> CHeightmapProcessor::PreprocessHeightmapTexture(void)
{
    assert(m_heightmapTexture == nullptr);
    assert(m_heightmapData != nullptr);
    ui32 textureId = CHeightmapProcessor::createTextureId();
    ui8* data = new ui8[m_heightmapData->getSizeX() * m_heightmapData->getSizeZ()];
    for(int i = 0; i < m_heightmapData->getSizeX(); i++)
    {
        for(int j = 0; j < m_heightmapData->getSizeZ(); j++)
        {
            f32 height = CHeightmapDataAccessor::getHeight(m_heightmapData, glm::vec3(i , 0.0f, j));
            height /= m_heightmapData->getMaxAltitude();
            ui8 color = static_cast<ui8>((height + 1.0) / 2.0 * 255);
            data[i + j * m_heightmapData->getSizeZ()] = color;
        }
    }
    glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA,
                 m_heightmapData->getSizeX(),
                 m_heightmapData->getSizeZ(),
                 0, GL_ALPHA, GL_UNSIGNED_BYTE, data);
    
    m_heightmapTexture = CTexture::constructCustomTexture("landscape.heightmap",
                                                          textureId,
                                                          m_heightmapData->getSizeX(),
                                                          m_heightmapData->getSizeZ());
    m_heightmapTexture->setWrapMode(GL_CLAMP_TO_EDGE);
    return m_heightmapTexture;
}

std::shared_ptr<CTexture> CHeightmapProcessor::PreprocessSplattingTexture(void)
{
    assert(m_splattingTexture == nullptr);
    ui32 textureId = CHeightmapProcessor::createTextureId();
    ui16* data = new ui16[m_heightmapData->getSizeX() * m_heightmapData->getSizeZ()];
    for(int i = 0; i < m_heightmapData->getSizeX(); i++)
    {
        for(int j = 0; j < m_heightmapData->getSizeZ(); j++)
        {
            data[i + j * m_heightmapData->getSizeZ()] = TO_RGB565(255, 0, 0);
            f32 height = CHeightmapDataAccessor::getHeight(m_heightmapData, glm::vec3(i , 0.0, j));
            f32 value = glm::dot(glm::vec3(0.0, 1.0, 0.0), CVertexBuffer::uncompressU8Vec4(m_heightmapData->getVertexNormal(i, j)));
            value = glm::degrees(acosf(value));
            assert(value >= 0.0);
            if(height >= 0.25 && value > 45.0)
            {
                data[i + j * m_heightmapData->getSizeX()] = TO_RGB565(0, 255, 0);
            }
            if(height < 0.25)
            {
                data[i + j * m_heightmapData->getSizeX()] = TO_RGB565(0, 0, 255);
            }
            
            if(i == 0 || j == 0 ||
               i == (m_heightmapData->getSizeX() - 1) ||
               j == (m_heightmapData->getSizeZ() - 1))
            {
                data[i + j * m_heightmapData->getSizeX()] = TO_RGB565(255, 0, 0);
            }
        }
    }
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 m_heightmapData->getSizeX(),
                 m_heightmapData->getSizeZ(),
                 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, data);
    
    m_splattingTexture = CTexture::constructCustomTexture("landscape.splatting",
                                                          textureId,
                                                          m_heightmapData->getSizeX(),
                                                          m_heightmapData->getSizeZ());
    m_splattingTexture->setWrapMode(GL_CLAMP_TO_EDGE);
    
    return m_splattingTexture;
}

void CHeightmapProcessor::_FillEdgesMaskTextureBlock(ui16* _data, ui32 _index, ui32 _edgesMaskWidth, ui32 _edgesMaskHeight, ui32 _textureBlockSize, const glm::vec3& _point, bool _reverse)
{
    for(ui32 j = 0; j < _edgesMaskHeight / 4; ++j)
    {
        f32 currentEdgeHeight = (static_cast<f32>(j) - static_cast<f32>(_edgesMaskHeight / 8.0)) / 16.0;
        f32 height = CHeightmapDataAccessor::getHeight(m_heightmapData, _point);

        ui32 indexOffset = _reverse == true ? (_edgesMaskWidth - 1) - _index + j * _edgesMaskWidth + _textureBlockSize : _index + j * _edgesMaskWidth + _textureBlockSize;
        _data[indexOffset] = TO_RGBA4444(0, 0, 0, 0);
        if(currentEdgeHeight < height && currentEdgeHeight > 0.0)
        {
            _data[indexOffset] = TO_RGBA4444(255, 0, 0, 255);
        }
        else
        {
            _data[indexOffset] = TO_RGBA4444(0, 255, 0, 0);
        }
    }
}

std::shared_ptr<CTexture> CHeightmapProcessor::PreprocessEdgesMaskTexture(void)
{
    ui32 edgesMaskWidth = 2048;
    ui32 edgesMaskHeight = 2048;

    ui32 textureId = CHeightmapProcessor::createTextureId();
    ui16* data = new ui16[edgesMaskWidth * edgesMaskHeight];
    for(ui32 i = 0; i < edgesMaskWidth; ++i)
    {
        CHeightmapProcessor::_FillEdgesMaskTextureBlock(data,
                                                        i,
                                                        edgesMaskWidth,
                                                        edgesMaskHeight,
                                                        0,
                                                        glm::vec3(static_cast<f32>(i) / static_cast<f32>(edgesMaskWidth) * m_heightmapData->getSizeX(),
                                                                  0.0f, 0.0f),
                                                        true);
        
        CHeightmapProcessor::_FillEdgesMaskTextureBlock(data,
                                                        i,
                                                        edgesMaskWidth,
                                                        edgesMaskHeight,
                                                        edgesMaskWidth * (edgesMaskHeight / 4),
                                                        glm::vec3(static_cast<f32>(i) / static_cast<f32>(edgesMaskWidth) * m_heightmapData->getSizeX(),
                                                                  0.0f, (m_heightmapData->getSizeX() - 1)),
                                                        false);
        
        
        CHeightmapProcessor::_FillEdgesMaskTextureBlock(data,
                                                        i,
                                                        edgesMaskWidth,
                                                        edgesMaskHeight,
                                                        edgesMaskWidth * (edgesMaskHeight / 4) * 2,
                                                        glm::vec3(0.0f, 0.0f, static_cast<float>(i) / static_cast<float>(edgesMaskWidth) * m_heightmapData->getSizeX()),
                                                        false);
        
        CHeightmapProcessor::_FillEdgesMaskTextureBlock(data,
                                                        i,
                                                        edgesMaskWidth,
                                                        edgesMaskHeight,
                                                        edgesMaskWidth * (edgesMaskHeight / 4) * 3,
                                                        glm::vec3((m_heightmapData->getSizeX() - 1), 0.0f, static_cast<float>(i) / static_cast<float>(edgesMaskWidth) * m_heightmapData->getSizeX()),
                                                        true);
    }
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, edgesMaskWidth, edgesMaskHeight, 0, GL_RGBA, GL_UNSIGNED_SHORT_4_4_4_4, data);
    
    m_edgesMaskTexture = CTexture::constructCustomTexture("landscape.edges",
                                                          textureId,
                                                          edgesMaskWidth,
                                                          edgesMaskHeight);
    m_edgesMaskTexture->setWrapMode(GL_CLAMP_TO_EDGE);
    
    return m_edgesMaskTexture;
}


std::shared_ptr<CTexture> CHeightmapProcessor::PreprocessSplattingDiffuseTexture(const std::shared_ptr<CMaterial> &_material)
{
    assert(m_screenSpaceTextureAccessor != nullptr);
    assert(m_diffuseTexture == nullptr);
    assert(m_splattingTexture != nullptr);
    m_diffuseTexture = m_screenSpaceTextureAccessor->Get_CustomScreenSpaceOperationTexture(_material, 2048, 2048);
    return m_diffuseTexture;
}

std::shared_ptr<CTexture> CHeightmapProcessor::PreprocessSplattingNormalTexture(const std::shared_ptr<CMaterial> &_material)
{
    assert(m_screenSpaceTextureAccessor != nullptr);
    assert(m_normalTexture == nullptr);
    assert(m_splattingTexture != nullptr);
    m_normalTexture = m_screenSpaceTextureAccessor->Get_CustomScreenSpaceOperationTexture(_material, 2048, 2048);
    return m_normalTexture;
}

CSharedIndexBuffer CHeightmapProcessor::createIndexBuffer(void)
{
    assert(m_chunkSizeX != 0);
    assert(m_chunkSizeZ != 0);
    
    CSharedIndexBuffer indexBuffer = std::make_shared<CIndexBuffer>((m_chunkSizeX - 1) * (m_chunkSizeZ - 1) * 6, GL_DYNAMIC_DRAW);
    CHeightmapProcessor::fillIndexBuffer(indexBuffer);
    return indexBuffer;
}

CSharedVertexBuffer CHeightmapProcessor::createVertexBuffer(ui32 widthOffset,
                                                            ui32 heightOffset,
                                                            ui32 numVertexes,
                                                            GLenum mode,
                                                            glm::vec3 *maxBound, glm::vec3 *minBound)
{
    assert(m_heightmapData != nullptr);
    assert(m_chunkSizeX != 0);
    assert(m_chunkSizeZ != 0);
    
    std::shared_ptr<CVertexBuffer> vertexBuffer = std::make_shared<CVertexBuffer>(numVertexes, mode);
    CHeightmapProcessor::fillVertexBuffer(vertexBuffer, widthOffset, heightOffset, numVertexes);
    CHeightmapProcessor::createChunkBound(widthOffset, heightOffset, maxBound, minBound);
    return vertexBuffer;
}

const std::tuple<glm::vec3, glm::vec3> CHeightmapProcessor::getChunkBounds(ui32 i, ui32 j) const
{
    assert(m_chunksBounds.size() != 0);
    return m_chunksBounds[i + j * m_numChunksZ];
}

CSharedMesh CHeightmapProcessor::getChunk(ui32 i, ui32 j)
{
    CSharedMesh mesh = nullptr;
    if(m_chunksUnused.size() != 0)
    {
        mesh = m_chunksUnused.at(m_chunksUnused.size() - 1);
        m_chunksUnused.pop_back();
        CHeightmapProcessor::fillVertexBuffer(mesh->getVertexBuffer(), i, j,
                                              m_chunkSizeX * m_chunkSizeZ);
        CHeightmapProcessor::fillIndexBuffer(mesh->getIndexBuffer());
        mesh->updateBounds();
    }
    else
    {
        glm::vec3 maxBound = glm::vec3(-4096.0, -4096.0, -4096.0);
        glm::vec3 minBound = glm::vec3(4096.0, 4096.0, 4096.0);
        
        CSharedVertexBuffer vertexBuffer = CHeightmapProcessor::createVertexBuffer(i, j,
                                                                                   m_chunkSizeX * m_chunkSizeZ,
                                                                                   GL_STATIC_DRAW,
                                                                                   &maxBound, &minBound);
        CSharedIndexBuffer indexBuffer = CHeightmapProcessor::createIndexBuffer();
        mesh = CMesh::constructCustomMesh("landscape.chunk", vertexBuffer, indexBuffer,
                                          maxBound, minBound);
    }
    
    CSharedHeightmapProcessingOperation operation = std::make_shared<CHeightmapProcessingOperation>(m_heightmapData,
                                                                                                    mesh->getVertexBuffer(),
                                                                                                    mesh->getIndexBuffer(),
                                                                                                    i, j);
    m_processingOperationQueue.push(operation);
    m_uniqueProcessingOperations.insert(std::make_pair(std::make_tuple(i, j), operation));
    
    return mesh;
}

void CHeightmapProcessor::freeChunk(CSharedMeshRef chunk, ui32 i, ui32 j)
{
    m_chunksUnused.push_back(chunk);
    const auto& iterator = m_uniqueProcessingOperations.find(std::make_tuple(i, j));
    if(iterator != m_uniqueProcessingOperations.end())
    {
        iterator->second->cancel();
    }
}

void CHeightmapProcessor::update(void)
{
    if(!m_processingOperationQueue.empty())
    {
        CSharedHeightmapProcessingOperation operation = m_processingOperationQueue.front();
        if(!operation->isCanceled() && !operation->isRunning())
        {
            operation->executeBackgroundThreadOperation();
        }
        else if(operation->isRunning() &&
                operation->isBackgroundThreadOperationDone() &&
                !operation->isMainThreadOperationDone())
        {
            operation->executeMainThreadOperation();
        }
        else if((operation->isRunning() &&
                 operation->isBackgroundThreadOperationDone() &&
                 operation->isMainThreadOperationDone()) ||
                operation->isCanceled())
        {
            m_processingOperationQueue.pop();
            const auto& iterator = m_uniqueProcessingOperations.find(std::make_tuple(operation->getIndexX(),
                                                                                     operation->getIndexZ()));
            if(iterator != m_uniqueProcessingOperations.end())
            {
                m_uniqueProcessingOperations.erase(iterator);
            }
        }
    }
}

void CHeightmapProcessor::createChunkBound(ui32 sizeXOffset, ui32 sizeZOffset,
                                           glm::vec3* maxBound, glm::vec3* minBound)
{
    assert(m_heightmapData != nullptr);
    assert(m_chunkSizeX != 0);
    assert(m_chunkSizeZ != 0);
    
    for(ui32 i = 0; i < m_chunkSizeX;++i)
    {
        for(ui32 j = 0; j < m_chunkSizeZ;++j)
        {
            glm::vec2 position = glm::vec2(i + sizeXOffset * m_chunkSizeX - sizeXOffset,
                                           j + sizeZOffset * m_chunkSizeZ - sizeZOffset);
            
            ui32 indexXOffset = static_cast<ui32>(position.x) < m_heightmapData->getSizeX() ?
            static_cast<ui32>(position.x) :
            static_cast<ui32>(m_heightmapData->getSizeX() - 1);
            
            ui32 indexZOffset = static_cast<ui32>(position.y) < m_heightmapData->getSizeZ() ?
            static_cast<ui32>(position.y) :
            static_cast<ui32>(m_heightmapData->getSizeZ() - 1);
            
            glm::vec3 point = m_heightmapData->getVertexPosition(indexXOffset,
                                                                 indexZOffset);
            
            *maxBound = CMeshData::calculateMaxBound(point, *maxBound);
            *minBound = CMeshData::calculateMinBound(point, *minBound);
        }
    }
}

void CHeightmapProcessor::fillVertexBuffer(CSharedVertexBufferRef vertexBuffer,
                                           ui32 sizeXOffset, ui32 sizeZOffset,
                                           ui32 numVertexes)
{
    assert(vertexBuffer != nullptr);
    SAttributeVertex* vertexData = vertexBuffer->lock();
    ui32 index = 0;
    for(ui32 i = 0; i < m_chunkSizeX;++i)
    {
        for(ui32 j = 0; j < m_chunkSizeZ;++j)
        {
            glm::vec2 position = glm::vec2(i + sizeXOffset * m_chunkSizeX - sizeXOffset,
                                           j + sizeZOffset * m_chunkSizeZ - sizeZOffset);
            
            ui32 indexXOffset = static_cast<ui32>(position.x) < m_heightmapData->getSizeX() ?
            static_cast<ui32>(position.x) :
            static_cast<ui32>(m_heightmapData->getSizeX() - 1);
            
            ui32 indexZOffset = static_cast<ui32>(position.y) < m_heightmapData->getSizeZ() ?
            static_cast<ui32>(position.y) :
            static_cast<ui32>(m_heightmapData->getSizeZ() - 1);
            
            glm::vec3 point = m_heightmapData->getVertexPosition(indexXOffset, indexZOffset);
            vertexData[index].m_position = point;
            glm::u16vec2 texcoord = CVertexBuffer::compressVec2(glm::vec2(static_cast<ui32>(point.x) / static_cast<f32>(m_heightmapData->getSizeX()),
                                                                          static_cast<ui32>(point.z) / static_cast<f32>(m_heightmapData->getSizeZ())));
            vertexData[index].m_texcoord = texcoord;
            
            glm::u8vec4 normal = m_heightmapData->getVertexNormal(indexXOffset, indexZOffset);
            vertexData[index].m_normal = normal;
            ++index;
        }
    }
    vertexBuffer->unlock();
}

void CHeightmapProcessor::fillIndexBuffer(CSharedIndexBufferRef indexBuffer)
{
    ui16* indexData = indexBuffer->lock();
    
    ui32 index = 0;
    for(ui32 i = 0; i < (m_chunkSizeX - 1); ++i)
    {
        for(ui32 j = 0; j < (m_chunkSizeZ - 1); ++j)
        {
            indexData[index] = i + j * m_chunkSizeX;
            index++;
            indexData[index] = i + (j + 1) * m_chunkSizeX;
            index++;
            indexData[index] = i + 1 + j * m_chunkSizeX;
            index++;
            
            indexData[index] = i + (j + 1) * m_chunkSizeX;
            index++;
            indexData[index] = i + 1 + (j + 1) * m_chunkSizeX;
            index++;
            indexData[index] = i + 1 + j * m_chunkSizeX;
            index++;
        }
    }
    indexBuffer->unlock();
}

void CHeightmapProcessor::generateTangentSpace(CSharedHeightmapDataRef heightmapData,
                                               CSharedVertexBufferRef vertexBuffer,
                                               CSharedIndexBufferRef indexBuffer)
{
    std::vector<glm::vec3> tangents, binormals;
    
    SAttributeVertex* vertexData = vertexBuffer->lock();
    ui32 numVertexes = vertexBuffer->getSize();
    
    ui16* indexData = indexBuffer->lock();
    ui32 numIndexes = indexBuffer->getSize();
    
    for (ui32 i = 0; i < numIndexes; i += 3 )
    {
        glm::vec3 v1 = vertexData[indexData[i + 0]].m_position;
        glm::vec3 v2 = vertexData[indexData[i + 1]].m_position;
        glm::vec3 v3 = vertexData[indexData[i + 2]].m_position;
        f32 s1 = CVertexBuffer::uncompressU16Vec2(vertexData[indexData[i + 0]].m_texcoord).x;
        f32 t1 = CVertexBuffer::uncompressU16Vec2(vertexData[indexData[i + 0]].m_texcoord).y;
        f32 s2 = CVertexBuffer::uncompressU16Vec2(vertexData[indexData[i + 1]].m_texcoord).x;
        f32 t2 = CVertexBuffer::uncompressU16Vec2(vertexData[indexData[i + 1]].m_texcoord).y;
        f32 s3 = CVertexBuffer::uncompressU16Vec2(vertexData[indexData[i + 2]].m_texcoord).x;
        f32 t3 = CVertexBuffer::uncompressU16Vec2(vertexData[indexData[i + 2]].m_texcoord).y;
        
        glm::vec3 t, b;
        CHeightmapProcessor::getTriangleBasis(v1, v2, v3, s1, t1, s2, t2, s3, t3, t, b);
        tangents.push_back(t);
        binormals.push_back(b);
    }
    
    for (ui32 i = 0; i < numVertexes; i++)
    {
        std::vector<glm::vec3> lrt, lrb;
        for (ui32 j = 0; j < numIndexes; j += 3)
        {
            if ((indexData[j + 0]) == i || (indexData[j + 1]) == i || (indexData[j + 2]) == i)
            {
                lrt.push_back(tangents[i]);
                lrb.push_back(binormals[i]);
            }
        }
        
        glm::vec3 tangentRes(0.0f, 0.0f, 0.0f);
        glm::vec3 binormalRes(0.0f, 0.0f, 0.0f);
        for (ui32 j = 0; j < lrt.size(); j++)
        {
            tangentRes += lrt[j];
            binormalRes += lrb[j];
        }
        tangentRes /= static_cast<f32>(lrt.size());
        binormalRes /= static_cast<f32>(lrb.size());
        
        glm::vec3 normal =  CVertexBuffer::uncompressU8Vec4(vertexData[i].m_normal);
        tangentRes = CHeightmapProcessor::ortogonalize(normal, tangentRes);
        binormalRes = CHeightmapProcessor::ortogonalize(normal, binormalRes);
        
        vertexData[i].m_tangent = CVertexBuffer::compressVec3(tangentRes);
    }
}

void CHeightmapProcessor::getTriangleBasis(const glm::vec3& E, const glm::vec3& F, const glm::vec3& G,
                                           f32 sE, f32 tE, f32 sF, f32 tF, f32 sG, f32 tG,
                                           glm::vec3& tangentX, glm::vec3& tangentY)
{
    glm::vec3 P = F - E;
    glm::vec3 Q = G - E;
    f32 s1 = sF - sE;
    f32 t1 = tF - tE;
    f32 s2 = sG - sE;
    f32 t2 = tG - tE;
    f32 pqMatrix[2][3];
    pqMatrix[0][0] = P[0];
    pqMatrix[0][1] = P[1];
    pqMatrix[0][2] = P[2];
    pqMatrix[1][0] = Q[0];
    pqMatrix[1][1] = Q[1];
    pqMatrix[1][2] = Q[2];
    f32 temp = 1.0f / ( s1 * t2 - s2 * t1);
    f32 stMatrix[2][2];
    stMatrix[0][0] = t2 * temp;
    stMatrix[0][1] = -t1 * temp;
    stMatrix[1][0] = -s2 * temp;
    stMatrix[1][1] = s1 * temp;
    f32 tbMatrix[2][3];
    tbMatrix[0][0] = stMatrix[0][0] * pqMatrix[0][0] + stMatrix[0][1] * pqMatrix[1][0];
    tbMatrix[0][1] = stMatrix[0][0] * pqMatrix[0][1] + stMatrix[0][1] * pqMatrix[1][1];
    tbMatrix[0][2] = stMatrix[0][0] * pqMatrix[0][2] + stMatrix[0][1] * pqMatrix[1][2];
    tbMatrix[1][0] = stMatrix[1][0] * pqMatrix[0][0] + stMatrix[1][1] * pqMatrix[1][0];
    tbMatrix[1][1] = stMatrix[1][0] * pqMatrix[0][1] + stMatrix[1][1] * pqMatrix[1][1];
    tbMatrix[1][2] = stMatrix[1][0] * pqMatrix[0][2] + stMatrix[1][1] * pqMatrix[1][2];
    tangentX = glm::vec3( tbMatrix[0][0], tbMatrix[0][1], tbMatrix[0][2] );
    tangentY = glm::vec3( tbMatrix[1][0], tbMatrix[1][1], tbMatrix[1][2] );
    tangentX = glm::normalize(tangentX);
    tangentY = glm::normalize(tangentY);
}

glm::vec3 CHeightmapProcessor::getClosestPointOnLine(const glm::vec3& a, const glm::vec3& b, const glm::vec3& p)
{
    glm::vec3 c = p - a;
    glm::vec3 V = b - a;
    f32 d = V.length();
    V = glm::normalize(V);
    f32 t = glm::dot( V, c );
    
    if ( t < 0.0f )
        return a;
    if ( t > d )
        return b;
    V *= t;
    return ( a + V );
}

glm::vec3 CHeightmapProcessor::ortogonalize(const glm::vec3& v1, const glm::vec3& v2)
{
    glm::vec3 v2ProjV1 = CHeightmapProcessor::getClosestPointOnLine( v1, -v1, v2 );
    glm::vec3 res = v2 - v2ProjV1;
    res = glm::normalize(res);
    return res;
}

