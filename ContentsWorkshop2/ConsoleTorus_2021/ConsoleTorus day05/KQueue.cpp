#include "KQueue.h"

KQueue::KQueue()
{
}

KQueue::~KQueue()
{
}

void KQueue::SetPos( int x, int y )
{
    _pos.x = x;
    _pos.y = y;
}

//{{ day05
int KQueue::GetTorusCount()
{
    return q0.size();
}

bool KQueue::IsFull()
{
    return q0.size() >= (size_t)dqmax;
}
//}} day05

void KQueue::DrawDeque()
{
    ::DrawDeque( q0, (int)_pos.x, (int)_pos.y, dqmax );
}

void KQueue::Update()
{
    // queue update routine here
}
