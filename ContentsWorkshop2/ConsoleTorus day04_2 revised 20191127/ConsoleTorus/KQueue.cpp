#include "KQueue.h"

KQueue::KQueue()
{
}

KQueue::~KQueue()
{
}

//{{ day04
void KQueue::SetPos( int x, int y )
{
    _pos.x = x;
    _pos.y = y;
}
//}} day04

void KQueue::DrawDeque()
{
	//{{ day04
    ::DrawDeque( q0, _pos.x, _pos.y, dqmax );
	//}} day04
}

void KQueue::Update()
{
    // queue update routine here
}
