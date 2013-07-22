//
//  CSceneFabricator.h
//  indie2dEngine
//
//  Created by Sergey Sergeev on 5/28/13.
//  Copyright (c) 2013 Sergey Sergeev. All rights reserved.
//

#ifndef CSceneFabricator_h
#define CSceneFabricator_h

#include "HCommon.h"

class CLight;
class CCamera;
class IGameObject;
class CSprite;
class CModel;
class CBillboard;
class CParticleEmitter;
class CTemplateAccessor;
class CResourceAccessor;

class CSceneFabricator
{
private:
    
protected:
    
    std::set<std::shared_ptr<IGameObject> > m_gameObjectsContainer;
    std::set<std::shared_ptr<CCamera> > m_camerasContainer;
    std::set<std::shared_ptr<CLight> > m_lightsContainer;
    
    std::shared_ptr<CTemplateAccessor> m_templateAccessor;
    std::shared_ptr<CResourceAccessor> m_resourceAccessor;
    
public:
    
    CSceneFabricator(std::shared_ptr<CTemplateAccessor> _templateAccessor, std::shared_ptr<CResourceAccessor> _resourceAccessor);
    virtual ~CSceneFabricator(void);
    
    std::shared_ptr<CCamera> CreateCamera(f32 _fov, f32 _near, f32 _far,const glm::ivec4& _viewport);
    void DeleteCamera(std::shared_ptr<CCamera> _camera);
    
    std::shared_ptr<CLight> CreateLight(void);
    void DeleteLight(std::shared_ptr<CLight> _light);
    
    std::shared_ptr<CSprite> CreateSprite(const std::string& _filename);
    void DeleteSprite(std::shared_ptr<CSprite> _sprite);
    
    std::shared_ptr<CModel> CreateModel(const std::string& _filename);
    void DeleteModel(std::shared_ptr<CModel> _model);
    
    std::shared_ptr<CBillboard> CreateBillboard(const std::string& _filename);
    void DeleteBillboard(std::shared_ptr<CBillboard> _billboard);
    
    std::shared_ptr<CParticleEmitter> CreateParticleEmitter(const std::string& _filename);
    void DeleteParticleEmitter(std::shared_ptr<CParticleEmitter> _particleEmitter);
};

#endif
