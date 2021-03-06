//
//  COcclusionQueryManager.h
//  ie3D-Core
//
//  Created by sergey.sergeev on 11/24/14.
//  Copyright (c) 2014 Sergey Sergeev. All rights reserved.
//

#ifndef COcclusionQueryManager_h
#define COcclusionQueryManager_h

#include "HCommon.h"
#include "HDeclaration.h"

class COcclusionQueryManager
{
private:
    
protected:
    
    CSharedMaterial m_material;
    
    std::map<std::string, std::set<ISharedOcclusionQueryHandler>> m_occludingGeometry;
    
public:
    
    COcclusionQueryManager(void);
    ~COcclusionQueryManager(void);
    
    void addToOcluddingQuery(const std::string& techniqueName, ISharedOcclusionQueryHandlerRef handler);
    void removeFromOcluddingQuery(const std::string& techniqueName, ISharedOcclusionQueryHandlerRef hadnler);
    
    void update(const std::string& techniqueName);
};


#endif
