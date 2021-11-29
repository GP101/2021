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
#include "KScene.h"

using namespace std::chrono;

bool    g_isGameLoop = true;
KScene  g_scene;

int main()
{
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
    while (g_isGameLoop) {
        _KInput.Update();
        _KTime.Update();
        std::this_thread::sleep_for(100ms);

        g_scene.Update();
        g_scene.Draw();

        if (_KInput(27)) {
            g_isGameLoop = false;
        }
    }
    return 0;
}
