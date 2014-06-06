//
//  IGameTransition.h
//  indie2dEngine
//
//  Created by Sergey Sergeev on 6/6/13.
//  Copyright (c) 2013 Sergey Sergeev. All rights reserved.
//

#ifndef IGameTransition_h
#define IGameTransition_h

#include "HCommon.h"
#include "IConfiguration.h"
#include "HDeclaration.h"
#include "IGameLoopHandler.h"

class IGameTransition :
public IConfigurationLoadingHandler,
public IGameLoopHandler
{
private:
    
protected:
    
    friend class IGameController;
    
    CSharedSceneGraph m_sceneGraph;
    CSharedSceneFabricator m_sceneFabricator;
    ISharedScene m_scene;
    
    CSharedRenderMgr m_renderMgr;
    CSharedSceneUpdateMgr m_sceneUpdateMgr;
    
    CSharedResourceAccessorRef m_resourceAccessor;
    ISharedScreenSpaceTextureAccessor m_screenSpaceTextureAccessor;
    
    std::string m_guid;
    
    bool m_isLoaded;
    
    virtual void _OnRegistered(void);
    virtual void _OnUnregistered(void);
    
    virtual void _OnActivate(void);
    virtual void _OnDeactivate(void);
    
    virtual void onConfigurationLoaded(ISharedConfigurationRef configuration, bool success);
    virtual void _OnLoaded(void);
    
    virtual void _OnGameLoopUpdate(f32 _deltatime);
    
public:
    
    IGameTransition(const std::string& filename,
                    ISharedGraphicsContextRef graphicsContext,
                    ISharedInputContextRef inputContext,
                    CSharedResourceAccessorRef resourceAccessor,
                    CSharedConfigurationAccessorRef configurationAccessor);
    
    virtual ~IGameTransition(void);

    std::string getGuid(void) const;
    
    ui32 getWindowWidth(void) const;
    ui32 getWindowHeight(void) const;
    
    void setCamera(CSharedCameraRef camera);
    
    void addModel(CSharedModelRef model);
    void removeModel(CSharedModelRef model);
    
    void setOcean(CSharedOceanRef ocean);
    void removeOcean(CSharedOceanRef ocean);
    
    void setSkyBox(CSharedSkyBoxRef skybox);
    void removeSkyBox(CSharedSkyBoxRef skybox);
    
    void setLandscape(CSharedLandscapeRef landscape);
    void removeLandscape(CSharedLandscapeRef landscape);
    
    void addParticleEmitter(CSharedParticleEmitterRef particleEmitter);
    void removeParticleEmitter(CSharedParticleEmitterRef particleEmitter);
    
    void addCustomGameObject(ISharedGameObjectRef gameObject);
    void removeCustomGameObject(ISharedGameObjectRef gameObject);
    
    void addGestureRecognizerHandler(ISharedGestureRecognizerHandlerRef handler);
    void removeGestureRecognizerHandler(ISharedGestureRecognizerHandlerRef handler);
    
    void addCollisionHandler(ISharedCollisionHandlerRef handler);
    void removeCollisionHandler(ISharedCollisionHandlerRef handler);
    
    CSharedCamera createCamera(f32 fov, f32 near, f32 far,const glm::ivec4& viewport);
    void deleteCamera(CSharedCameraRef camera);
    
    CSharedModel createModel(const std::string& filename);
    void deleteModel(CSharedModelRef model);
    
    CSharedOcean createOcean(const std::string& filename);
    void deleteOcean(CSharedOceanRef ocean);
    
    CSharedSkyBox createSkyBox(const std::string& filename);
    void deleteSkyBox(CSharedSkyBoxRef skyBox);
    
    CSharedLandscape createLandscape(const std::string& filename);
    void deleteLandscape(CSharedLandscapeRef landscape);
    
    CSharedParticleEmitter createParticleEmitter(const std::string& filename);
    void deleteParticleEmitter(CSharedParticleEmitterRef particleEmitter);
    
    ui32 Get_CurrentNumTriangles(void);
    ui32 Get_TotalNumTriangles(void);
};

#endif 
