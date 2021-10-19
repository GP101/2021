#pragma once
#include "MyUtil.h"
#include "KTowerOfHanoi.h"

struct Scene
{
    double m_animTime = 0.0;
    double m_x = -2.0;
    double m_xoffset = 0.1;
	KTowerOfHanoi m_hanoi;

	void Start();
    void Update(double elapsedTime);
	void Draw(double elapsedTime);
};
