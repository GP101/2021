#pragma once
#include <deque>
#include "TorusDefines.h"

class KQueue
{
private:
    std::deque<TORUS> q0;
    int dqmax = 5;
    KVector2    _pos;

public:
    KQueue();
    ~KQueue();

    void SetPos( int x, int y );
    void SetSize(int size) {
        dqmax = size;
    }
    int GetSize() { return dqmax; }
	//{{ day05
    int GetTorusCount();
	//}} day05

    void PopFront() {
        q0.pop_front();
    }
    void PopBack() {
        q0.pop_back();
    }
	//{{ day05
    TORUS Back()
    {
        return q0.back();
    }
    TORUS Front() {
        return q0.front();
    }
	//}} day05
    void PushFront(const TORUS& v) {
        q0.push_front(v);
    }
    void PushBack(const TORUS& v) {
        q0.push_back(v);
    }
	//{{ day05
    bool IsFull();
	//}} day05
    void DrawDeque();
    void Update();

};
