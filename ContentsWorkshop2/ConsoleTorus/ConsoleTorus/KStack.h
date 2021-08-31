#pragma once
#include "TorusDefines.h"

class KStack
{
private:
    TORUS   _buffer[10];
    int     _sp;
    int     _maxSize;

public:
    KStack();
    void SetSize(int size);
    int GetSize() { return _maxSize; }
    void Push( TORUS t );
    void Pop();
    // @pre must not empty
    TORUS Top();
    bool Empty();
    bool IsFull();
    void Draw( int x, int y );
};
