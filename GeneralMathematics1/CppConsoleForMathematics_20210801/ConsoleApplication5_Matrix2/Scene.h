#pragma once
#include "MyUtil.h"

struct Scene
{
    double m_animTime = 0.0;
    double m_x = -2.0;
    double m_xoffset = 0.1;

    void Update(double elapsedTime);
};
