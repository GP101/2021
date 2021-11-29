#include "KScene.h"
#include "KInput.h"

KScene::KScene()
{
    _stackStampOld = 0;
    _stackStampNew = 0;
}

KScene::~KScene()
{
}

void KScene::Initialize(KInitParam initParam)
{
    _param = initParam;
    for (int i = 0; i < initParam.numLanes; ++i) {
        _lanes.push_back( KLane() );
        _queues.push_back(KQueue());
    }
    _pos = KVector2(initParam.x, initParam.y);
    int tx = (int)_pos.x;
    int ty = (int)_pos.y;
    for (size_t i = 0; i < _lanes.size(); ++i) {
        KLane& l = _lanes[i];
        l.SetPos( tx, ty );
        l.SetHeight(initParam.laneHeight);
        KQueue& q = _queues[i];
        q.SetPos( tx, ty + initParam.laneHeight );
        q.SetSize(initParam.queueSize);
        tx += 4;
    }
    _stack.SetSize(initParam.stackSize);
    int numSkipLane = (_param.numLanes - 1) / 2;
    tx = initParam.x + numSkipLane * 4;
    ty = initParam.y + _lanes[0].GetHeight() + _queues[0].GetSize();
    _stackPos.x = tx;
    _stackPos.y = ty;
    //_stack.SetPos( tx, ty );
}

void KScene::Update()
{
    if (_KInput('a')) {
        _stackStampNew += 1;
        _stackPosOld = _stackPos;
        _stackPos.x -= 4;
    }
    else if (_KInput('d')) {
        _stackStampNew += 1;
        _stackPosOld = _stackPos;
        _stackPos.x += 4;
   }
}

void KScene::Draw()
{
    for (size_t i = 0; i < _lanes.size(); ++i) {
        KLane& l = _lanes[i];
        l.Draw();
    }
    for (size_t i = 0; i < _queues.size(); ++i) {
        KQueue& q = _queues[i];
        q.DrawDeque();
    }
    // observer design pattern
    if (_stackStampOld != _stackStampNew) {
        DrawText((int)_stackPosOld.x
            , (int)_stackPosOld.y
            , _stack.GetSize() + 1, "   ");
        _stackStampOld = _stackStampNew;
    }
    _stack.Draw((int)_stackPos.x, (int)_stackPos.y);
}
