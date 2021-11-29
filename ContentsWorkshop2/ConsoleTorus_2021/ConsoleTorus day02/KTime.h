#pragma once
#include <windows.h>
#include <mmsystem.h>

class KTime
{
public:
    double  deltaTime;
private:
    DWORD   _begin;
    DWORD   _end;
public:
    static KTime& GetInstance()
    {
        static KTime i;
        return i;
    }

    KTime();
    ~KTime();
    void Update();
};

#define _KTime KTime::GetInstance()