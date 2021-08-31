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
	//{{ day04
    void SetSize(int size);
    int GetSize() { return _maxSize; }
	//}} day04
    void Push( TORUS t );
    void Pop();
    // @pre must not empty
    TORUS Top();
    bool Empty();
    void Draw( int x, int y );
};
