//
//  HMEEnums.h
//  ie3D-EMap
//
//  Created by sergey.sergeev on 7/23/14.
//
//

#ifndef HMEEnums_h
#define HMEEnums_h

enum E_MODEL_BRUSH_ARROW
{
    E_MODEL_BRUSH_ARROW_X = 0,
    E_MODEL_BRUSH_ARROW_Y,
    E_MODEL_BRUSH_ARROW_Z,
    E_MODEL_BRUSH_ARROW_MAX
};

enum E_MODEL_BRUSH_PLANE
{
    E_MODEL_BRUSH_PLANE_YZ = 0,
    E_MODEL_BRUSH_PLANE_XZ,
    E_MODEL_BRUSH_PLANE_XY,
    E_MODEL_BRUSH_PLANE_MAX
};

enum E_LANDSCAPE_EDIT_MODE
{
    E_LANDSCAPE_EDIT_MODE_HEIGHTMAP = 0,
    E_LANDSCAPE_EDIT_MODE_TEXTURES,
    E_LANDSCAPE_EDIT_MODE_GAMEOBJECTS
};

#endif
