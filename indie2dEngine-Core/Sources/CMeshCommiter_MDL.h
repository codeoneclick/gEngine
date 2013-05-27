//
//  CMeshCommiter_MDL.h
//  indie2dEngine
//
//  Created by Sergey Sergeev on 5/26/13.
//  Copyright (c) 2013 Sergey Sergeev. All rights reserved.
//

#ifndef CMeshCommiter_MDL_h
#define CMeshCommiter_MDL_h

#include "IResourceCommiter.h"

class CTextureHeader;
class CTextureCommiter_PVR final : public IResourceCommiter
{
private:
    
protected:
    
    std::shared_ptr<CTextureHeader> m_header;
    
public:
    
    CTextureCommiter_PVR(const std::string& _guid, std::shared_ptr<CTextureHeader> _header,  std::shared_ptr<IResource> _resource);
    ~CTextureCommiter_PVR(void);
    
    void Commit(void);
};


#endif /* defined(__indie2dEngine__CMeshCommiter_MDL__) */
