#pragma once
#include "KLane.h"
#include "KQueue.h"
#include "KStack.h"
#include <vector>
#include "KVector2.h"

class KScene
{
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
    KInitParam              _param;
    std::vector<KLane>      _lanes;
    std::vector<KQueue>     _queues;
    KStack                  _stack;
    int                     _stackStampOld;
    int                     _stackStampNew;
    KVector2                _pos;
    KVector2                _stackPosOld;
    KVector2                _stackPos;
public:
    KScene();
    ~KScene();
    void Initialize(KInitParam initParam);
    void Update();
    void Draw();
};

