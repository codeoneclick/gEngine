//
//  CGameRootTransition.cpp
//  indi2dEngine
//
//  Created by Sergey Sergeev on 5/14/13.
//  Copyright (c) 2013 Sergey Sergeev. All rights reserved.
//

#include "CGameRootTransition.h"
#include "CResourceAccessor.h"
#include "CMaterial.h"
#include "CShader.h"
#include "CGameLoopExecutor.h"
#include "CRenderMgr.h"
#include "CSceneUpdateMgr.h"
#include "CRenderOperationWorldSpace.h"
#include "CCommonOS.h"

#ifdef __APPLE__
#include "COGLContext_iOS.h"
#else
#endif

const std::string g_vsScreenShader = "CommonScreen.vert";
const std::string g_fsScreenShader = "CommonScreen.frag";

CGameRootTransition::CGameRootTransition(const void* _glWindow)
{
#ifdef __APPLE__
    
	UIView* glWindow = (__bridge UIView*)_glWindow;
    assert([[glWindow layer] isKindOfClass:[CAEAGLLayer class]]);
    m_glContext = std::make_shared<COGLContext_iOS>(static_cast<CAEAGLLayer*>(glWindow.layer));
    
#else
    
    // TODO :
    
#endif
    
    std::shared_ptr<CShader> shader = m_resourceFabricator->CreateShader(g_vsScreenShader, g_fsScreenShader);
    
    std::shared_ptr<CMaterial> material = std::make_shared<CMaterial>(shader);
    material->Set_RenderState(E_RENDER_STATE_CULL_MODE, false);
    material->Set_RenderState(E_RENDER_STATE_DEPTH_MASK, true);
    material->Set_RenderState(E_RENDER_STATE_DEPTH_TEST, false);
    material->Set_RenderState(E_RENDER_STATE_BLEND_MODE, false);
    
    material->Set_CullFaceMode(GL_FRONT);
    material->Set_BlendFunctionSource(GL_SRC_ALPHA);
    material->Set_BlendFunctionDest(GL_ONE_MINUS_SRC_ALPHA);
    
    m_renderMgr = std::make_shared<CRenderMgr>(m_glContext, material);
    std::shared_ptr<CRenderOperationWorldSpace> worldSpaceRenderOperation = std::make_shared<CRenderOperationWorldSpace>(Get_ScreenWidth(),
                                                                                                                         Get_ScreenHeight(),
                                                                                                                         "common.world.space.render.operation");
    m_renderMgr->RegisterWorldSpaceRenderOperation("common.world.space.render.operation", worldSpaceRenderOperation);
    
    m_sceneUpdateMgr = std::make_shared<CSceneUpdateMgr>();
    
    ConnectToGameLoop(m_renderMgr);
    ConnectToGameLoop(m_sceneUpdateMgr);
}

CGameRootTransition::~CGameRootTransition(void)
{
    
}