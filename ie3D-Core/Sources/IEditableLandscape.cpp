//
//  IEditableLandscape.cpp
//  ie3D-Core
//
//  Created by Sergey Sergeev on 5/27/14.
//  Copyright (c) 2014 Sergey Sergeev. All rights reserved.
//

#include "IEditableLandscape.h"
#include "CHeightmapProcessor.h"

IEditableLandscape::IEditableLandscape(void) :
m_editableSize(4),
m_editableStrength(1),
m_editableFalloffCoefficient(0),
m_editableSmoothCoefficient(0),
m_heightmapProcessor(nullptr)
{
    
}

IEditableLandscape::~IEditableLandscape(void)
{
    
}

void IEditableLandscape::setHeightmapProcessor(CSharedHeightmapProcessorRef heightmapProcessor)
{
    assert(heightmapProcessor != nullptr);
    m_heightmapProcessor = heightmapProcessor;
}

void IEditableLandscape::setEditableSize(ui32 value)
{
    m_editableSize = value;
}

void IEditableLandscape::setEditableStrength(ui32 value)
{
    m_editableStrength = value;
}

void IEditableLandscape::setEditableFalloffCoefficient(ui32 value)
{
    m_editableFalloffCoefficient = value;
}

void IEditableLandscape::setEditableSmoothCoefficient(ui32 value)
{
    m_editableSmoothCoefficient = value;
}

void IEditableLandscape::pressureHeight(const glm::vec3& point, f32 pressureForce)
{
	i32 minIndX = static_cast<i32>(floor(point.x - m_editableSize));
	i32 minIndZ = static_cast<i32>(floor(point.z - m_editableSize));
	i32 maxIndX = static_cast<i32>(floor(point.x + m_editableSize));
	i32 maxIndZ = static_cast<i32>(floor(point.z + m_editableSize));
    std::vector<std::tuple<ui32, ui32, f32>> modifiedHeights;
	for(i32 x = minIndX; x < maxIndX; x++)
	{
        for(i32 z = minIndZ; z < maxIndZ; z++)
        {
            if((x < 0) || (z < 0) ||
               x >= m_heightmapProcessor->getSizeX() ||
               z >= m_heightmapProcessor->getSizeZ())
                continue;
            
            f32 height = m_heightmapProcessor->getHeight(glm::vec3(x, 0.0, z));
            f32 distance = glm::length(glm::vec3(x - point.x, 0.0, z - point.z));
            
            if (distance > m_editableSize)
                continue;
            
            f32 riseCoefficient = distance / static_cast<f32>(m_editableSize);
            riseCoefficient = 1.0 - riseCoefficient * riseCoefficient;
            f32 deltaHeight = pressureForce * riseCoefficient * (m_editableStrength * 0.1);
            height += deltaHeight;
            
            i32 delimiter = 1;
            for(i32 i = x - m_editableSmoothCoefficient; i <= x + m_editableSmoothCoefficient; ++i)
            {
                for(i32 j = z - m_editableSmoothCoefficient; j <= z + m_editableSmoothCoefficient; ++j)
                {
                    if(i > 0 && j > 0 &&
                       i < m_heightmapProcessor->getSizeX() && j < m_heightmapProcessor->getSizeZ())
                    {
                        height += m_heightmapProcessor->getHeight(glm::vec3(i, 0.0, j));
                        delimiter++;
                    }
                }
            }
            height /= static_cast<f32>(delimiter);

            modifiedHeights.push_back(std::make_tuple(x, z, height));
        }
	}
    m_heightmapProcessor->updateHeightmapData(modifiedHeights);
    
    ui32 offsetX = MAX_VALUE(minIndX, 0);
    ui32 offsetZ = MAX_VALUE(minIndZ, 0);
    ui32 subWidth = MIN_VALUE(maxIndX, m_heightmapProcessor->getSizeX() - 1) - offsetX;
    ui32 subHeight = MIN_VALUE(maxIndZ, m_heightmapProcessor->getSizeZ() - 1) - offsetZ;

    m_heightmapProcessor->updateHeightmap(offsetX, offsetZ,
                                          subWidth, subHeight);
}

void IEditableLandscape::generateVertecesData(i32 size, f32 frequency, i32 octaves, ui32 seed)
{
    assert(m_heightmapProcessor != nullptr);
    m_heightmapProcessor->generateVertecesData(size, frequency, octaves, seed);
}