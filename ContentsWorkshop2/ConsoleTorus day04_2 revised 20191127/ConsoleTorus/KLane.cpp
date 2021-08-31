#include "KLane.h"
#include "TorusDefines.h"
#include "KTime.h"

KLane::KLane()
{
    _height = 0;
    _torusState = ETorusState::BEGIN;
	//{{ day04
    _torus = TORUS::TORUS_RED;
	//}} day04
}

KLane::~KLane()
{
}


//{{ day04
void KLane::SetPos( int x, int y )
{
    _pos.x = x;
    _pos.y = y;
    _torusPos = _pos;
}
//}} day04

void KLane::SetTorusCallback(TorusEndCallback cb)
{
    _torusCallback = cb;
}

void KLane::SetHeight(int h)
{
    _height = h;
}

void KLane::InitTorus(KVector2 v, TORUS t)
{
    //{{ day04
    _torusPos = _pos;
	//}} day04
    _torusPosBegin = _torusPos;
    _torusVel = v;
    _torus = t;
    _torusState = ETorusState::MOVING;
}

void KLane::Draw()
{
    //{{ day04
    int x = _pos.x;
    int y = _pos.y;
	//}} day04
    for (int row = 0; row < _height; ++row) {
        const int ty = row + y;
        DrawText(x, ty, "...");
    }
    DrawText(_torusPos.x, _torusPos.y, g_torusText[_torus]);
}

void KLane::Update()
{
    if (_torusState == ETorusState::BEGIN) {
        //
    }
    else if (_torusState == ETorusState::MOVING) {
        _torusPos = _torusPos 
            + _torusVel * _KTime.deltaTime;
        const double offset = _torusPos.y - _torusPosBegin.y;
        if (offset >= _height) {
            _torusState = ETorusState::END;
        }
    }
    else if (_torusState == ETorusState::END) {
        // access queue, push torus into a queue
        if (_torusCallback != nullptr) {
            _torusCallback(this);
        }
    }
}
