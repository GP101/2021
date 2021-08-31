#include "KScene.h"
#include "KInput.h"
//{{ day05
#include <functional>
#include <cstdlib>

using namespace std::placeholders;
//}} day05

KScene::KScene()
{
    _stackStampOld = 0;
    _stackStampNew = 0;
	//{{ day05
    _sceneState = SCENE_STATE_NONE;
	//}} day05
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
    int tx = _pos.x;
    int ty = _pos.y;
    for (int i = 0; i < _lanes.size(); ++i) {
        KLane& l = _lanes[i];
        l.SetPos( tx, ty );
        l.SetHeight(initParam.laneHeight);
		//{{ day05
        l.SetTorusCallback( std::bind( &KScene::TorusEndCallback, this, _1 ) );
        l.SetId(i);
		//}} day05
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
	//{{ day05
    for (int i = 0; i < _lanes.size(); ++i) {
        KLane& l = _lanes[i];
        l.Update();
    }
    for (int i = 0; i < _queues.size(); ++i) {
        KQueue& q = _queues[i];
        q.Update();
    }
    //_stack.Update();

    void( KScene::*stateCallback[4])() = {
        &KScene::_Update_SCENE_STATE_NONE,
        &KScene::_Update_SCENE_STATE_INITIALIZED,
        &KScene::_Update_SCENE_STATE_PLAYING,
        &KScene::_Update_SCENE_STATE_END
    };
    ( this->*stateCallback[_sceneState] )( );
	//}} day05

	//{{ day05
    if (_KInput(KInput::VKEY_LEFT)) {
        _stackStampNew += 1;
        _stackPosOld = _stackPos;
        _stackPos.x -= 4;
    }
    else if (_KInput( KInput::VKEY_RIGHT )) {
	//}} day05
        _stackStampNew += 1;
        _stackPosOld = _stackPos;
        _stackPos.x += 4;
   }
}

void KScene::Draw()
{
    for (int i = 0; i < _lanes.size(); ++i) {
        KLane& l = _lanes[i];
        l.Draw();
    }
    for (int i = 0; i < _queues.size(); ++i) {
        KQueue& q = _queues[i];
        q.DrawDeque();
    }
    // observer design pattern
    if (_stackStampOld != _stackStampNew) {
        DrawText(_stackPosOld.x
            , _stackPosOld.y
            , _stack.GetSize() + 1, "   ");
        _stackStampOld = _stackStampNew;
    }
    _stack.Draw(_stackPos.x, _stackPos.y);
}

//{{ day05
void KScene::TorusEndCallback( KLane* pLane )
{
    TORUS t = (TORUS)( std::rand() % (int)TORUS_MAX );
    KVector2 vel = KVector2( 0, 1 + std::rand() % 2 );
    pLane->InitTorus( vel, t );
}

void KScene::_Update_SCENE_STATE_NONE()
{
    _sceneState = SCENE_STATE_INITIALIZED;
}

void KScene::_Update_SCENE_STATE_INITIALIZED()
{
    for (int i = 0; i < _param.numLanes; ++i) {
        TORUS t = (TORUS)( std::rand() % (int)TORUS_MAX );
        KVector2 vel = KVector2( 0, 1 + std::rand() % 2 );
        KLane& lane = _lanes[i];
        lane.InitTorus( vel, t );
    }
    _sceneState = SCENE_STATE_PLAYING;
}

void KScene::_Update_SCENE_STATE_PLAYING()
{
}

void KScene::_Update_SCENE_STATE_END()
{
}
//}} day05