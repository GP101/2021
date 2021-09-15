#include "Scene.h"
#include "KVector2.h"

void DrawLine(double x, double y, double x2, double y2, char ch)
{
    ScanLine(int(x + 100), int(-y + 60), int(x2 + 100), int(-y2 + 60), ch);
}

void Scene::Update(double elapsedTime)
{
    KVector2 v0(0, 0);
    KVector2 v1(50, 20);
    DrawLine(v0.x, v0.y, v1.x, v1.y, '*');
    char buffer[80];
    sprintf_s(buffer, sizeof(buffer), "%g", elapsedTime);
    PutText(0, 0, buffer);
}
