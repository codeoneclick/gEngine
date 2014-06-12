//
//  CLandscape.h
//  iGaia
//
//  Created by sergey.sergeev on 1/16/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef CLandscape_h
#define CLandscape_h

#include "IGameObject.h"
#include "HDeclaration.h"
#include "IEditableLandscape.h"

class CLandscapeChunk;
class CLandscapeEdges;

class CLandscape : public IGameObject,
public IEditableLandscape
{
private:

    CSharedHeightmapProcessor m_heightmapProcessor;
    std::vector<CSharedLandscapeChunk> m_chunks;
    CSharedLandscapeEdges m_edges;
    ISharedConfiguration m_configuration;
    
    CSharedTexture m_prerenderedSplattingDiffuseTexture;
    CSharedTexture m_prerenderedSplattingNormalTexture;
    
    CSharedMaterial m_splattingDiffuseMaterial;
    CSharedMaterial m_splattingNormalMaterial;
    
    bool m_isSplattingDiffuseTexturePrerendered;
    bool m_isSplattingNormalTexturePrerendered;
    
    void prerenderSplattingDiffuseTexture(void);
    void prerenderSplattingNormalTexture(void);
    
protected:

    void onSceneUpdate(f32 deltatime);
    
    void onResourceLoaded(ISharedResourceRef resource, bool success);
    void onConfigurationLoaded(ISharedConfigurationRef configuration, bool success);
    
    i32  zOrder(void);
    bool checkOcclusion(void);
    ui32 numTriangles(void);
    void onBind(const std::string& mode);
    void onDraw(const std::string& mode);
    void onUnbind(const std::string& mode);
    void onBatch(const std::string& mode);

public:

    CLandscape(CSharedResourceAccessorRef resourceAccessor,
               ISharedScreenSpaceRenderAccessorRef screenSpaceTextureAccessor);
    ~CLandscape(void);
    
    void setCamera(CSharedCameraRef camera);
    void setLightSource(CSharedLightSourceRef lightSource,
                        E_LIGHT_SOURCE index);
    
    void setRenderMgr(CSharedRenderMgrRef renderMgr);
    void setSceneUpdateMgr(CSharedSceneUpdateMgrRef sceneUpdateMgr);
    
    void listenRenderMgr(bool value);
    void listenSceneUpdateMgr(bool value);
    
    std::vector<ISharedGameObject> getChunks(void) const;

    CSharedTexture getHeightmapTexture(void) const;
    
    ui32 getHeightmapSizeX(void) const;
    ui32 getHeightmapSizeZ(void) const;
    
    f32 getHeight(const glm::vec3& position) const;
};

#endif
