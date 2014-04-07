//
//  HDeclaration.h
//  indieEngineCore
//
//  Created by Sergey Sergeev on 4/7/14.
//  Copyright (c) 2014 Sergey Sergeev. All rights reserved.
//

#ifndef indieEngineCore_HDeclaration_h
#define indieEngineCore_HDeclaration_h

#include "HCommon.h"

class CTexture;
typedef std::shared_ptr<CTexture> CSharedTexture;
typedef const CSharedTexture& CSharedTextureRef;

class CShader;
typedef std::shared_ptr<CShader> CSharedShader;
typedef const CSharedShader& CSharedShaderRef;

class CMesh;
typedef std::shared_ptr<CMesh> CSharedMesh;
typedef const CSharedMesh& CSharedMeshRef;

class CSkeleton;
typedef std::shared_ptr<CSkeleton> CSharedSkeleton;
typedef const CSharedSkeleton& CSharedSkeletonRef;

class CSequence;
typedef std::shared_ptr<CSequence> CSharedSequence;
typedef const CSharedSequence& CSharedSequenceRef;

class IResourceLoader;
typedef std::shared_ptr<IResourceLoader> ISharedResourceLoader;
typedef const ISharedResourceLoader& ISharedResourceLoaderRef;

class CTextureLoader;
typedef std::shared_ptr<CTextureLoader> CSharedTextureLoader;
typedef const CSharedTextureLoader& CSharedTextureLoaderRef;

class CShaderLoader;
typedef std::shared_ptr<CShaderLoader> CSharedShaderLoader;
typedef const CSharedShaderLoader& CSharedShaderLoaderRef;

class CMeshLoader;
typedef std::shared_ptr<CMeshLoader> CSharedMeshLoader;
typedef const CSharedMeshLoader& CSharedMeshLoaderRef;

class CSkeletonLoader;
typedef std::shared_ptr<CSkeletonLoader> CSharedSkeletonLoader;
typedef const CSharedSkeletonLoader& CSharedSkeletonLoaderRef;

class CSequenceLoader;
typedef std::shared_ptr<CSequenceLoader> CSharedSequenceLoader;
typedef const CSharedSequenceLoader& CSharedSequenceLoaderRef;

class CMeshData;
typedef std::shared_ptr<CMeshData> CSharedMeshData;
typedef const CSharedMeshData& CSharedMeshDataRef;

class CFrameData;
typedef std::shared_ptr<CFrameData> CSharedFrameData;
typedef const CSharedFrameData& CSharedFrameDataRef;

class CSequenceData;
typedef std::shared_ptr<CSequenceData> CSharedSequenceData;
typedef const CSharedSequenceData& CSharedSequenceDataRef;

class CVertexBuffer;
typedef std::shared_ptr<CVertexBuffer> CSharedVertexBuffer;
typedef const CSharedVertexBuffer& CSharedVertexBufferRef;

class CIndexBuffer;
typedef std::shared_ptr<CIndexBuffer> CSharedIndexBuffer;
typedef const CSharedIndexBuffer& CSharedIndexBufferRef;

class CBone;
typedef std::shared_ptr<CBone> CSharedBone;
typedef const CSharedBone& CSharedBoneRef;

class CSkeletonData;
typedef std::shared_ptr<CSkeletonData> CSharedSkeletonData;
typedef const CSharedSkeletonData& CSharedSkeletonDataRef;

#endif
