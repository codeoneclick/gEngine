//
//  CResourceLoader.h
//  indie2dEngine
//
//  Created by Sergey Sergeev on 5/17/13.
//  Copyright (c) 2013 Sergey Sergeev. All rights reserved.
//

#ifndef CResourceLoader_h
#define CResourceLoader_h

#include "HCommon.h"
#include "HDeclaration.h"
#include "IGameLoopHandler.h"

class CResourceLoader : public IGameLoopHandler
{
private:
    
protected:
    
    std::unordered_map<std::string, ISharedResourceLoadingOperation> m_operationsQueue;
    std::unordered_map<std::string, ISharedResource> m_resourceContainer;
    
    std::mutex m_mutex;
    ui8 m_isRunning;
    std::thread m_thread;
    
    void onGameLoopUpdate(f32 deltatime);
    void onThreadUpdate(void);
    
    void _OnGameLoopUpdate(f32 _deltatime);
    
public:
    
    CResourceLoader(void);
    ~CResourceLoader(void);
    
    CSharedTexture startTextureLoadingOperation(const std::string& filename);
    
    CSharedShader startShaderLoadingOperation(const std::string& vsFilename,
                                              const std::string& fsFilename);
    
    CSharedMesh startMeshLoadingOperation(const std::string& meshFilename,
                                          const std::string& skeletonFilename,
                                          const std::string& sequenceFilename);
    
    std::tuple<CSharedMesh, CSharedSkeleton, CSharedSequence> startMeshLoadingOperation(const std::string& filename) const;
    
	void unloadResource(ISharedResourceRef resource);
};

#endif 
