#pragma once
#include <deque>
#include "TorusDefines.h"

class KQueue
{
private:
    std::deque<TORUS> q0;
    int dqmax = 5;
	//{{ day04
    KVector2    _pos;
	//}} day04

public:
    KQueue();
    ~KQueue();

	//{{ day04
    void SetPos( int x, int y );
    void SetSize(int size) {
        dqmax = size;
    }
    int GetSize() { return dqmax; }
	//}} day04

    void PopFront() {
        q0.pop_front();
    }
    void PopBack() {
        q0.pop_back();
    }
    void PushFront(const TORUS& v) {
        q0.push_front(v);
    }
    void PushBack(const TORUS& v) {
        q0.push_back(v);
    }
	//}} day04
    void DrawDeque();
	//{{ day04
    void Update();
};
