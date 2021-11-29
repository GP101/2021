#include "KLane.h"
#include "TorusDefines.h"
#include "KTime.h"

KLane::KLane()
{
    _height = 0;
    _torusState = ETorusState::BEGIN;
}

KLane::~KLane()
{
}

void KLane::SetTorusCallback(TorusEndCallback cb)
{
    _torusCallback = cb;
}

void KLane::SetHeight(int h)
{
    _height = h;
}

void KLane::InitTorus(int x, int y, KVector2 v, TORUS t)
{
    _torusPos = KVector2(x, y);
    _torusPosBegin = _torusPos;
    _torusVel = v;
    _torus = t;
    _torusState = ETorusState::MOVING;
}

void KLane::Draw(int x, int y)
{
    for (int row = 0; row < _height; ++row) {
        const int ty = row + y;
        DrawText(x, ty, "...");
    }
    DrawText(int(_torusPos.x), int(_torusPos.y), g_torusText[_torus]);
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
