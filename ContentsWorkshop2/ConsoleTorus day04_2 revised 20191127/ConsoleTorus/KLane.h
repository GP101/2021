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
    //{{ day04
    KVector2            _pos;
	//}} day04
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
	//{{ day04
    void SetPos( int x, int y );
	//}} day04
    void SetTorusCallback(TorusEndCallback cb);
    void SetHeight(int h);
	//{{ day04
    int  GetHeight() { return _height; }
	//}} day04
    void InitTorus(KVector2 v, TORUS t);
    void Draw();
    void Update();
};

