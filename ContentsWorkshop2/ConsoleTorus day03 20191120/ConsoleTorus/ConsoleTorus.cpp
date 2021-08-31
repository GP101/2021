#include <iostream>
#include <stack>
#include <conio.h>
#include "TorusDefines.h"
#include "KStack.h"
#include <deque>
#include "KQueue.h"
#include "KInput.h"
#include "KTime.h"
//{{ day03
#include <thread>
#include <chrono>
#include "KLane.h"

using namespace std::chrono;
//}} day03

bool g_isGameLoop = true;

//{{ day03
void MyTorusCallback(KLane* plane)
{
    g_isGameLoop = false;
}
//}} day03

int main()
{
    //{{ day03
    KLane   lane;
    lane.SetTorusCallback(MyTorusCallback);
    lane.SetHeight(10);
    lane.InitTorus(1, 1, KVector2(0, 2), TORUS_BLUE);
    //}} day03
    while (g_isGameLoop) {
        _KInput.Update();
        _KTime.Update();

        //{{ day03
        std::this_thread::sleep_for(100ms);

        lane.Update();
        lane.Draw(1, 1);
		//}} day03

        if (_KInput(27)) {
            g_isGameLoop = false;
        }
    }
    return 0;
}
