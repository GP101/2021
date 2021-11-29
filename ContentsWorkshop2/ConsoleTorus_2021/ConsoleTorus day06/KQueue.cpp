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

int KQueue::GetTorusCount()
{
    return q0.size();
}

bool KQueue::IsFull()
{
    return q0.size() >= (size_t)dqmax;
}

void KQueue::DrawDeque()
{
    ::DrawDeque( q0, (int)_pos.x, (int)_pos.y, dqmax );
}

void KQueue::Update()
{
    // queue update routine here
}

//{{ day06
TORUS KQueue::GetAt(int i)
{
    return q0[i];
}

bool KQueue::Erase(int i)
{
    if (i >= GetSize())
        return false;

    q0.erase(q0.begin() + i);
    return true;
}
//}} day06
