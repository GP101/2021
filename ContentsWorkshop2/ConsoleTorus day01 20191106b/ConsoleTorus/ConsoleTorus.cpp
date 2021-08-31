#include <iostream>
#include <stack>
#include <conio.h>
#include "TorusDefines.h"
#include "KStack.h"

int main()
{
    KStack  s0;
    int ch = 0;
    while (ch != 27) {
        ch = _getch();
        if (ch == 'a')
            s0.Push(TORUS_RED);
        if (ch == 's')
            s0.Push(TORUS_GREEN);
        if (ch == 'x')
            s0.Pop();
        s0.Draw(10, 10);
    }
    return 0;
}