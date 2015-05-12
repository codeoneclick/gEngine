//
//  CHeightmapContainer.hpp
//  ie3D-Core
//
//  Created by sergey.sergeev on 5/11/15.
//  Copyright (c) 2015 Sergey Sergeev. All rights reserved.
//

inline glm::ivec2 CHeightmapContainer::getSize(void) const
{
    return m_size;
};

inline glm::ivec2 CHeightmapContainer::getChunksNum(void) const
{
    return m_chunksNum;
};

inline glm::ivec2 CHeightmapContainer::getChunkSize(void) const
{
    return m_chunkSize;
};

inline glm::ivec2 CHeightmapContainer::getChunkLODSize(E_LANDSCAPE_CHUNK_LOD LOD) const
{
    assert(LOD >= 0 && LOD < E_LANDSCAPE_CHUNK_LOD_MAX);
    return m_chunkLODsSizes[LOD];
}

inline CHeightmapContainer::SUncomressedVertex* CHeightmapContainer::getUncopressedVertices(void) const
{
    assert(m_uncompressedVertices != nullptr);
    return m_uncompressedVertices;
};

inline CHeightmapContainer::SCompressedVertex* CHeightmapContainer::getCompressedVertices(void) const
{
    assert(m_compressedVertices != nullptr);
    return m_compressedVertices;
};

inline CHeightmapContainer::SFace* CHeightmapContainer::getFaces(void) const
{
    assert(m_faces != nullptr);
    return m_faces;
};

inline void CHeightmapContainer::attachUncompressedVertexToVBO(i32 i, i32 j, ui32 vboIndex, ui32 vboVertexIndex)
{
    i32 index = i + j * m_size.x;
    assert(m_uncompressedVertices[index].m_containsInVBO.size() <= kMaxContainsInVBO);
    m_uncompressedVertices[index].m_containsInVBO.push_back(glm::ivec2(vboIndex, vboVertexIndex));
};

inline std::vector<glm::ivec2> CHeightmapContainer::attachedVerticesToVBO(i32 i, i32 j)
{
    i32 index = i + j * m_size.x;
    assert(m_uncompressedVertices[index].m_containsInVBO.size() != 0 && m_uncompressedVertices[index].m_containsInVBO.size() <= kMaxContainsInVBO);
    return m_uncompressedVertices[index].m_containsInVBO;
};

inline glm::vec3 CHeightmapContainer::getVertexPosition(ui32 i, ui32 j) const
{
    return m_compressedVertices[i + j * m_size.x].m_position;
};

inline glm::uint32 CHeightmapContainer::getCompressedVertexTexcoord(ui32 i, ui32 j) const
{
    return m_compressedVertices[i + j * m_size.x].m_texcoord;
};

inline glm::vec2 CHeightmapContainer::getUncompressedVertexTexcoord(ui32 i, ui32 j) const
{
    return glm::unpackUnorm2x16(m_compressedVertices[i + j * m_size.x].m_texcoord);
};

inline glm::uint32 CHeightmapContainer::getCompressedVertexNormal(ui32 i, ui32 j) const
{
    return m_compressedVertices[i + j * m_size.x].m_normal;
};

inline glm::vec3 CHeightmapContainer::getUncompressedVertexNormal(ui32 i, ui32 j) const
{
    glm::vec4 normal = glm::unpackSnorm4x8(m_compressedVertices[i + j * m_size.x].m_normal);
    return glm::vec3(normal.x, normal.y, normal.z);
};

