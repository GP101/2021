#include <iostream>
#include <stack>
#include <conio.h>
#include "TorusDefines.h"
#include "KStack.h"
//{{ day02
#include <deque>
#include "KQueue.h"
#include "KInput.h"
#include "KTime.h"

bool g_isGameLoop = true;
//}} day02

int main()
{
    //{{ day02
    KQueue  q0;
	//}} day02
    KStack  s0;

    //{{ day02
    q0.PushBack(TORUS::TORUS_BLUE);
    while (g_isGameLoop) {
        _KInput.Update();
        _KTime.Update();

        Sleep( 100 );
        // render FSP(frame per second)
        {
            char buff[100];
            snprintf( buff, sizeof( buff ), "%g", _KTime.deltaTime );
            DrawText( 1, 1, buff );
        }

        q0.Update();
        q0.DrawDeque(10, 10);

        if (_KInput(27)) {
            g_isGameLoop = false;
        }
    }
	//}} day02
    return 0;
}
