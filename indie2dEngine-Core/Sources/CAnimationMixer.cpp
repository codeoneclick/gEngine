//
//  CAnimationMixer.cpp
//  indie2dEngine
//
//  Created by Sergey Sergeev on 8/13/13.
//  Copyright (c) 2013 Sergey Sergeev. All rights reserved.
//

#include "CAnimationMixer.h"
#include "CMesh.h"
#include "CSkeleton.h"
#include "CBone.h"
#include "CSequence.h"

CAnimationMixer::CAnimationMixer(std::shared_ptr<CMesh> _mesh, std::shared_ptr<CSkeleton> _skeleton) :
m_mesh(_mesh),
m_skeleton(_skeleton),
m_oldSequence(nullptr),
m_currentSequence(nullptr),
m_animationTime(0.0f)
{
    m_skeletonGuid = m_skeleton->CreateTransformations();
    m_vertexBufferGuid = m_mesh->Get_VertexBuffer()->CreateReference();
}

CAnimationMixer::~CAnimationMixer(void)
{
    
}

void CAnimationMixer::AddSequence(const std::string& _name, std::shared_ptr<CSequence> _sequence)
{
    if(m_sequences.find(_name) != m_sequences.end())
    {
        assert(false);
        return;
    }
    m_sequences.insert(std::make_pair(_name, _sequence));
}

void CAnimationMixer::SetAnimation(const std::string& _name)
{
    if(m_sequences.find(_name) == m_sequences.end())
    {
        return;
    }
    
    if(m_sequences.find(_name)->second == m_currentSequence)
    {
        return;
    }
    
    if(m_sequences.find(_name)->second->IsLoaded() && m_sequences.find(_name)->second->IsCommited())
    {
        m_oldSequence = m_currentSequence;
        m_currentSequence = m_sequences.find(_name)->second;
        CAnimationMixer::_BindSequence();
    }
}

void CAnimationMixer::MixAnimation(const std::string& _name)
{
    if(m_sequences.find(_name) == m_sequences.end())
    {
        assert(false);
        return;
    }
    
    if(m_sequences.find(_name)->second == m_currentSequence)
    {
        return;
    }
    
    m_oldSequence = m_currentSequence;
    m_currentSequence = m_sequences.find(_name)->second;
    CAnimationMixer::_BindSequence();
}

void CAnimationMixer::GoTo(const std::string& _name, i32 _frame)
{
    
}

void CAnimationMixer::_BindSequence(void)
{
    assert(m_skeleton != nullptr);
    assert(m_currentSequence != nullptr);
    
    std::shared_ptr<CFrame> frame = m_currentSequence->Get_AnimationFrame(0);
    std::shared_ptr<CBone> bone;
    
    for (i32 i = 0; i < m_skeleton->Get_NumBones(); ++i)
    {
        glm::vec3 position = frame->Get_Position(i);
        glm::quat rotation = frame->Get_Rotation(i);
        glm::vec3 scale = frame->Get_Scale(i);
        
        glm::mat4x4 matrixTranslation = glm::translate(glm::mat4(1.0f), position);
        glm::mat4x4 matrixRotation = glm::toMat4(rotation);
        glm::mat4x4 matrixScale = glm::scale(glm::mat4x4(1.0f), scale);
        assert(m_skeleton->Get_Transformations(m_skeletonGuid) != nullptr);
        m_skeleton->Get_Transformations(m_skeletonGuid)[i] = matrixTranslation * matrixRotation * matrixScale;
    }
    
    m_skeleton->Update(m_skeletonGuid);
    m_skeleton->BindTransformation();
}

void CAnimationMixer::OnUpdate(f32 _deltatime)
{
    assert(m_mesh != nullptr);
    assert(m_skeleton != nullptr);
    
    _deltatime = 0.02f;
    
    if(m_currentSequence)
    {
        m_animationTime += _deltatime;
        
        std::function<void(void)> function = [this]()
        {
            f32 animationDeltaTime = m_animationTime * m_currentSequence->Get_Fps();
            i32 floorAnimationDeltaTime = static_cast<i32>(floorf(animationDeltaTime));
            i32 frameIndex_01 = floorAnimationDeltaTime % m_currentSequence->Get_NumFrames();
            i32 frameIndex_02 = (frameIndex_01 + 1) % m_currentSequence->Get_NumFrames();
            f32 interpolation = animationDeltaTime - static_cast<f32>(floorAnimationDeltaTime);
            
            std::shared_ptr<CFrame> frame_01 = m_currentSequence->Get_AnimationFrame(frameIndex_01);
            std::shared_ptr<CFrame> frame_02 = m_currentSequence->Get_AnimationFrame(frameIndex_02);
            
            std::shared_ptr<CBone> bone;
            
            for (i32 i = 0; i < m_skeleton->Get_NumBones(); ++i)
            {
                glm::vec3 position = glm::mix(frame_01->Get_Position(i), frame_02->Get_Position(i), interpolation );
                glm::quat rotation = glm::slerp(frame_01->Get_Rotation(i), frame_02->Get_Rotation(i), interpolation);
                glm::vec3 scale = glm::mix(frame_01->Get_Scale(i), frame_02->Get_Scale(i), interpolation);
                
                glm::mat4x4 matrixTranslation = glm::translate(glm::mat4(1.0f), position);
                glm::mat4x4 matrixRotation = glm::toMat4(rotation);
                glm::mat4x4 matrixScale = glm::scale(glm::mat4x4(1.0f), scale);
                
                assert(m_skeleton->Get_Transformations(m_skeletonGuid) != nullptr);
                m_skeleton->Get_Transformations(m_skeletonGuid)[i] = matrixTranslation * matrixRotation * matrixScale;
            }
            m_skeleton->Update(m_skeletonGuid);
            
            SVertex* vertexData = m_mesh->Get_VertexBuffer()->Lock(m_vertexBufferGuid);
            for(i32 i = 0; i <  m_mesh->Get_VertexBuffer()->Get_Size(); ++i)
            {
                glm::vec3 bonePosition(0.0f);
                glm::vec3 boneNormal(0.0f);
                for(i32 j = 0; j < m_mesh->Get_SourceData()[i].m_bones.size(); ++j)
                {
                    std::shared_ptr<CBone> bone = m_skeleton->Get_Bone(m_mesh->Get_SourceData()[i].m_bones[j].m_id);
                    
                    glm::mat4x4 boneTransformation = (*bone->Get_Transformation());
                    
                    f32 weight = m_mesh->Get_SourceData()[i].m_bones[j].m_weigth;
                    if(j == 0)
                    {
                        bonePosition = glm::transform(m_mesh->Get_SourceData()[i].m_position, boneTransformation) * weight;
                        boneNormal = glm::transform(m_mesh->Get_SourceData()[i].m_normal, boneTransformation) * weight;
                    }
                    else
                    {
                        bonePosition += glm::transform(m_mesh->Get_SourceData()[i].m_position, boneTransformation) * weight;
                        boneNormal += glm::transform(m_mesh->Get_SourceData()[i].m_normal, boneTransformation) * weight;
                    }
                }
                vertexData[i].m_position = bonePosition;
                vertexData[i].m_normal = CVertexBuffer::CompressVec3(boneNormal);
                vertexData[i].m_texcoord = m_mesh->Get_SourceData()[i].m_texcoord;
            }
        };
        gcdpp::impl::DispatchAsync(gcdpp::queue::GetGlobalQueue(gcdpp::queue::GCDPP_DISPATCH_QUEUE_PRIORITY_LOW), function);

    }
    else
    {
        std::function<void(void)> function = [this]()
        {
            SVertex* vertexData = m_mesh->Get_VertexBuffer()->Lock(m_vertexBufferGuid);
            for(i32 i = 0; i <  m_mesh->Get_VertexBuffer()->Get_Size(); ++i)
            {
                vertexData[i].m_position = m_mesh->Get_SourceData()[i].m_position;
                vertexData[i].m_texcoord = m_mesh->Get_SourceData()[i].m_texcoord;
                vertexData[i].m_normal = CVertexBuffer::CompressVec3(m_mesh->Get_SourceData()[i].m_normal);
            }
        };
        gcdpp::impl::DispatchAsync(gcdpp::queue::GetGlobalQueue(gcdpp::queue::GCDPP_DISPATCH_QUEUE_PRIORITY_LOW), function);
    }
}

void CAnimationMixer::OnDraw(void)
{
    m_mesh->Get_VertexBuffer()->Unlock(m_vertexBufferGuid);
}


