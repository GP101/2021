#include "Scene.h"

void Scene::Update(double elapsedTime)
{
    //ScanLine(0, 0, g_width - 1, 0, '*');
    y += dy;
    ScanLine(0, 0, g_width - 1, y, 'O');
    if (y <= 0 || y >= g_height) {
        dy = -dy;
    }
    char buffer[80];
    sprintf_s(buffer, sizeof(buffer), "%g", elapsedTime);
    PutText(0, 0, buffer);
}
