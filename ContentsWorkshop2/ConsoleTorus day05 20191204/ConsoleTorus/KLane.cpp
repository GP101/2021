#include "KLane.h"
#include "TorusDefines.h"
#include "KTime.h"

KLane::KLane()
{
    _height = 0;
    _torusState = ETorusState::BEGIN;
    _torus = TORUS::TORUS_RED;
}

KLane::~KLane()
{
}

void KLane::SetPos( int x, int y )
{
    _pos.x = x;
    _pos.y = y;
    _torusPos = _pos;
}

//{{ day05
void KLane::SetTorusCallback( std::function<void( KLane* )> cb)
//}} day05
{
    _torusCallback = cb;
}

void KLane::SetHeight(int h)
{
    _height = h;
}

//{{ day05
void KLane::InitTorus(KVector2 velocity, TORUS t)
//}} day05
{
    _torusPos = _pos;
    _torusPosBegin = _torusPos;
	//{{ day05
    _torusVel = velocity;
	//}} day05
    _torus = t;
    _torusState = ETorusState::MOVING;
}

void KLane::Draw()
{
    int x = _pos.x;
    int y = _pos.y;
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

//{{ day05
TORUS KLane::GetTorus()
{
    return _torus;
}
//}} day05
