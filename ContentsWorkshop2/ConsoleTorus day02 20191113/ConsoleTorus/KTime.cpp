#include "KTime.h"
#include <mmsystem.h>

#pragma comment(lib,"winmm.lib")

KTime::KTime()
{
    _begin = timeGetTime();
    _end = timeGetTime();
}

KTime::~KTime()
{
}

void KTime::Update()
{
    _begin = _end;
    _end = timeGetTime();
    deltaTime = (_end - _begin) / 1000.0;
}