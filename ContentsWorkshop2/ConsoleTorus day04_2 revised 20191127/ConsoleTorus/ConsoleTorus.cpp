#include <iostream>
#include <stack>
#include <conio.h>
#include "TorusDefines.h"
#include "KStack.h"
#include <deque>
#include "KQueue.h"
#include "KInput.h"
#include "KTime.h"
#include <thread>
#include <chrono>
#include "KLane.h"
//{{ day04
#include "KScene.h"
//}} day04
using namespace std::chrono;

bool    g_isGameLoop = true;
//{{ day04
KScene  g_scene;
//}} day04

int main()
{
    //{{ day04
    ShowConsoleCursor( false );
    KScene::KInitParam param;
    {
        param.laneHeight = 8;
        param.numLanes = 3;
        param.queueSize = 5;
        param.stackSize = 5;
        param.x = 1;
        param.y = 1;
    }

    g_scene.Initialize( param );
	//}} day04
    while (g_isGameLoop) {
        _KInput.Update();
        _KTime.Update();
        std::this_thread::sleep_for(100ms);

		//{{ day04
        g_scene.Update();
        g_scene.Draw();
		//}} day04

        if (_KInput(27)) {
            g_isGameLoop = false;
        }
    }
    return 0;
}
