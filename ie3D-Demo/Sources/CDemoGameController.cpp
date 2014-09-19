//
//  CKOTHWorkflow.cpp
//  indie2dEngine
//
//  Created by Sergey Sergeev on 6/12/13.
//  Copyright (c) 2013 Sergey Sergeev. All rights reserved.
//

#include "CDemoGameController.h"
#include "IGraphicsContext.h"
#include "IInputContext.h"
#include "CDemoGameTransition.h"
#include "CConfigurationAccessor.h"
#include "IOGLWindow.h"

CDemoGameController::CDemoGameController(void)
{
    
}

CDemoGameController::~CDemoGameController(void)
{
    
}

std::shared_ptr<IGameTransition> CDemoGameController::CreateKOTHInGameTransition(const std::string &filename, ISharedOGLWindowRef window)
{
#if defined (__IOS__)
    std::shared_ptr<IGraphicsContext> graphicsContext = IGraphicsContext::createGraphicsContext(window, E_PLATFORM_API_IOS);
    std::shared_ptr<IInputContext> gestureRecognizerContext = IInputContext::createInputContext(window, E_PLATFORM_API_IOS);
#elif defined(__WIN32__)
    std::shared_ptr<IGraphicsContext> graphicsContext = IGraphicsContext::createGraphicsContext(window, E_PLATFORM_API_WIN32);
    std::shared_ptr<IInputContext> gestureRecognizerContext = IInputContext::createInputContext(window, E_PLATFORM_API_WIN32);
#elif defined(__NDK__)
    std::shared_ptr<IGraphicsContext> graphicsContext = IGraphicsContext::createGraphicsContext(window, E_PLATFORM_API_NDK);
    std::shared_ptr<IInputContext> gestureRecognizerContext = IInputContext::createInputContext(window, E_PLATFORM_API_NDK);
#elif defined(__OSX__)
    std::shared_ptr<IGraphicsContext> graphicsContext = IGraphicsContext::createGraphicsContext(window, E_PLATFORM_API_OSX);
    std::shared_ptr<IInputContext> gestureRecognizerContext = IInputContext::createInputContext(window, E_PLATFORM_API_OSX);
#endif
    
    m_configurationAccessor = std::make_shared<CConfigurationAccessor>();
    std::shared_ptr<CDemoGameTransition> mainTransition = std::make_shared<CDemoGameTransition>(filename,
                                                                                                graphicsContext,
                                                                                                gestureRecognizerContext,
                                                                                                m_resourceAccessor,
                                                                                                m_configurationAccessor);
    mainTransition->initScene();
    m_configurationAccessor->loadGameTransitionConfiguration(filename, mainTransition);
    assert(mainTransition != nullptr);
    return mainTransition;
}