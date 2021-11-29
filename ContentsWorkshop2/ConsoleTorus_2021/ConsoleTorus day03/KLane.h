#pragma once
#include "TorusDefines.h"

class KLane
{
public:
    typedef void (*TorusEndCallback)(KLane* plane);
private:
    enum ETorusState
    {
        BEGIN,
        MOVING,
        END
    };
private:
    int                 _height;
    KVector2            _torusPos;
    KVector2            _torusPosBegin;
    KVector2            _torusVel;
    TORUS               _torus;
    ETorusState         _torusState;
    TorusEndCallback    _torusCallback;

public:
    KLane();
    ~KLane();
    void SetTorusCallback(TorusEndCallback cb);
    void SetHeight(int h);
    void InitTorus(int x, int y, KVector2 v, TORUS t);
    void Draw(int x, int y);
    void Update();
};

