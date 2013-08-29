//
//  CAnimationMixer.h
//  indie2dEngine
//
//  Created by Sergey Sergeev on 8/13/13.
//  Copyright (c) 2013 Sergey Sergeev. All rights reserved.
//

#ifndef CAnimationMixer_h
#define CAnimationMixer_h

#include "HCommon.h"

class CSequence;
class CMesh;
class CSVertexBuffer;
class CSIndexBuffer;
class CSkeleton;

class CAnimationMixer
{
private:
    
protected:
    
    std::map<std::string, std::shared_ptr<CSequence> > m_sequences;
    std::shared_ptr<CMesh> m_mesh;
    std::shared_ptr<CSkeleton> m_skeleton;
    
    std::shared_ptr<CSequence> m_oldSequence;
    std::shared_ptr<CSequence> m_currentSequence;
    
    f32 m_animationTime;
    
    std::string m_skeletonGuid;
    ui32 m_vertexBufferGuid;
    ui32 m_indexBufferGuid;
    
    void _BindSequence(void);
    
public:
    
    CAnimationMixer(std::shared_ptr<CMesh> _mesh, std::shared_ptr<CSkeleton> _skeleton);
    ~CAnimationMixer(void);
    
    inline const ui32 Get_VertexBufferGuid(void) const
    {
        return m_vertexBufferGuid;
    };
    
    inline const ui32 Get_IndexBufferGuid(void) const
    {
        return m_indexBufferGuid;
    };
    
    void AddSequence(const std::string& _name, std::shared_ptr<CSequence> _sequence);
    void SetAnimation(const std::string& _name);
    void MixAnimation(const std::string& _name);
    void GoTo(const std::string& _name, i32 _frame);
    void OnUpdate(f32 _deltatime);
    void OnDraw(void);
};

#endif 
