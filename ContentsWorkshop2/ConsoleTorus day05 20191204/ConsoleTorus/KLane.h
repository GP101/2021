#pragma once
#include "TorusDefines.h"
//{{ day05
#include <functional>
//}} day05

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
	//{{ day05
    int                 _id;
	//}} day05
    KVector2            _pos;
    int                 _height;
    KVector2            _torusPos;
    KVector2            _torusPosBegin;
    KVector2            _torusVel;
    TORUS               _torus;
    ETorusState         _torusState;
	//{{ day05
    std::function<void( KLane* )>
                        _torusCallback;
    //}} day05

public:
    KLane();
    ~KLane();
	//{{ day05
    int GetId() { return _id; }
    void SetId(int id) { _id = id; }
	//}} day05
    void SetPos( int x, int y );

	//{{ day05
    void SetTorusCallback( std::function<void( KLane* )> cb);
	//}} day05
    void SetHeight(int h);
    int  GetHeight() { return _height; }
    //{{ day05
    void InitTorus(KVector2 velocity, TORUS t);
	//}} day05
    void Draw();
    void Update();
	//{{ day05
    TORUS GetTorus();
	//}} day05
};

