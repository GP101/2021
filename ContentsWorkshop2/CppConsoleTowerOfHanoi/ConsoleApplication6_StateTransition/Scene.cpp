#include "Scene.h"
#include "KVector2.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "KMatrix2.h"
#include <complex>

double g_drawScale = 1.0;

void DrawLine(double x, double y, double x2, double y2, char ch)
{
	const int centerx = g_width / 2;
	const int centery = g_height / 2;
    ScanLine(int(x * g_drawScale + centerx), int(-y * g_drawScale + centery)
        , int(x2 * g_drawScale + centerx), int(-y2 * g_drawScale + centery), ch);
}

void DrawLine(KVector2 v0, KVector2 v1, char ch)
{
	const int centerx = g_width / 2;
	const int centery = g_height / 2;
	ScanLine(int(v0.x * g_drawScale + centerx), int(-v0.y * g_drawScale + centery)
        , int(v1.x * g_drawScale + centerx), int(-v1.y * g_drawScale + centery), ch);
}

void Scene::Start()
{
	m_hanoi.Initialize(5);
}

void Scene::Update(double elapsedTime)
{
    m_animTime += elapsedTime;

	m_hanoi.Iterate(elapsedTime);
}

void Scene::Draw(double elapsedTime)
{
	g_drawScale = 1.0;
	DrawLine(-g_width / 2, 0, g_width / 2, 0, '.');
	DrawLine(0, -g_height / 2, 0, g_height / 2, '.');

	m_hanoi.Draw();

	char buffer[80];
	sprintf_s(buffer, sizeof(buffer), "%g", elapsedTime);
	PutText(0, 0, buffer);
}
