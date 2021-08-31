#pragma once
#include <deque>
#include "TorusDefines.h"

class KQueue
{
private:
    std::deque<TORUS> q0;
    int dqmax = 5;

public:
    KQueue();
    ~KQueue();

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
    void DrawDeque(int x, int y);
    void Update();
};
