#pragma once
#include "KLane.h"
#include "KQueue.h"
#include "KStack.h"
#include <vector>
#include "KVector2.h"

class KScene
{
private:
    enum ESceneState
    {
        SCENE_STATE_NONE,
        SCENE_STATE_INITIALIZED,
        SCENE_STATE_PLAYING,
        SCENE_STATE_END
    };
public:
    struct KInitParam {
        int     x;
        int     y;
        int     numLanes;
        int     laneHeight;
        int     queueSize;
        int     stackSize;
    };
private:
    ESceneState             _sceneState;
    KInitParam              _param;
    std::vector<KLane>      _lanes;
    std::vector<KQueue>     _queues;
	//{{ day06
    int                     _queueDataStamp;
    int                     _queueDataStampNew;
	//}} day06
    KStack                  _stack;
    int                     _stackStampOld;
    int                     _stackStampNew;
    KVector2                _pos;
    KVector2                _stackPosOld;
    KVector2                _stackPos;
	//{{ day06
    int                     _stackLane;
	//}} day06

public:
    KScene();
    ~KScene();
    void Initialize(KInitParam initParam);
    void Update();
    void Draw();
    void TorusEndCallback( KLane* pTorus );

private:
    void _Update_SCENE_STATE_NONE();
    void _Update_SCENE_STATE_INITIALIZED();
    void _Update_SCENE_STATE_PLAYING();
    void _Update_SCENE_STATE_END();

	//{{ day06
    bool _EraseLineFromQueue(int lineFrom0);
    void _RemoveMatchTorusFromQueue();
	//}} day06
};

