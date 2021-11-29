#pragma once
#include "TorusDefines.h"
#include <functional>

class KLane
{
private:
    enum ETorusState
    {
        BEGIN,
        MOVING,
        END
    };
private:
    int                 _id;
    KVector2            _pos;
    int                 _height;
    KVector2            _torusPos;
    KVector2            _torusPosBegin;
    KVector2            _torusVel;
    TORUS               _torus;
    ETorusState         _torusState;
    std::function<void( KLane* )>
                        _torusCallback;

public:
    KLane();
    ~KLane();
    int GetId() { return _id; }
    void SetId(int id) { _id = id; }
    void SetPos( int x, int y );
    void SetTorusCallback( std::function<void( KLane* )> cb);
    void SetHeight(int h);
    int  GetHeight() { return _height; }
    void InitTorus(KVector2 velocity, TORUS t);
    void Draw();
    void Update();
    TORUS GetTorus();
};

