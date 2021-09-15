#pragma once
#include "MyUtil.h"

struct Scene
{
    int y = 0;
    int dy = 1;

    void Update(double elapsedTime);
};
