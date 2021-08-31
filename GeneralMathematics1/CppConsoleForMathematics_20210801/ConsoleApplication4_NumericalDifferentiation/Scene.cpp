#include "Scene.h"
#include "KVector2.h"
#define _USE_MATH_DEFINES
#include <cmath>

double g_drawScale = 1.0;

void DrawLine(double x, double y, double x2, double y2, char ch)
{
    //ScanLine(int(x + 100), int(-y + 60), int(x2 + 100), int(-y2 + 60), ch);
    ScanLine(int(x* g_drawScale + 100), int(-y * g_drawScale + 60)
        , int(x2 * g_drawScale + 100), int(-y2 * g_drawScale + 60), ch);
}

void DrawLine(KVector2 v0, KVector2 v1, char ch)
{
    //ScanLine(int(v0.x + 100), int(-v0.y + 60), int(v1.x + 100), int(-v1.y + 60), ch);
    ScanLine(int(v0.x * g_drawScale + 100), int(-v0.y * g_drawScale + 60)
        , int(v1.x * g_drawScale + 100), int(-v1.y * g_drawScale + 60), ch);
}

double SquareFunction(double x)
{
    return 0.5 * x * x;
}

double ExpFunction(double base_, double x)
{
    return std::pow(base_, x);
}

double LogFunction(double base_, double x)
{
    return std::log10(x) / std::log10(base_);
}

double SineFunction(double x)
{
    return sin(x);
}

double AsineFunction(double x)
{
    return asin(x);
}

using FUNCTION = double(*)(double x);
using FUNCTION2 = double(*)(double base_, double x);

double NewtonsDifference(FUNCTION f, double x, double dx = 0.0001)
{
    const double y0 = f(x);
    const double y1 = f(x + dx);
    return (y1 - y0) / dx;
}

double NewtonsDifference2(FUNCTION2 f, double base_, double x, double dx = 0.0001)
{
    const double y0 = f(base_, x);
    const double y1 = f(base_, x + dx);
    return (y1 - y0) / dx;
}

double SymmetricDifference(FUNCTION f, double x, double dx = 0.0001)
{
    const double y0 = f(x - dx);
    const double y1 = f(x + dx);
    return (y1 - y0) / (2.0 * dx);
}

double SymmetricDifference2(FUNCTION2 f, double base_, double x, double dx = 0.0001)
{
    const double y0 = f(base_, x - dx);
    const double y1 = f(base_, x + dx);
    return (y1 - y0) / (2.0 * dx);
}

void DrawFunction(FUNCTION callback, double beginX, double endX, double xstep, char ch)
{
    double oldX;
    double oldY;
    double x = beginX;
    double y = callback(x);
    oldX = x;
    oldY = y;
    while (x < endX)
    {
        x += xstep;
        y = callback(x);
        DrawLine(KVector2(oldX, oldY), KVector2(x, y), ch);
        oldX = x;
        oldY = y;
    }//while
}

void DrawFunction2(FUNCTION2 ExpCallback, double base_, double beginX, double endX, double xstep, char ch)
{
    double oldX;
    double oldY;
    double x = beginX;
    double y = ExpCallback(base_, x);
    oldX = x;
    oldY = y;
    while (x < endX)
    {
        x += xstep;
        y = ExpCallback(base_, x);
        DrawLine(KVector2(oldX, oldY), KVector2(x, y), ch);
        oldX = x;
        oldY = y;
    }//while
}


void Scene::Update(double elapsedTime)
{
    double base_ = 3.0;

    m_animTime += elapsedTime;
    if (m_animTime > 0.01)
    {
        m_x += m_xoffset;
        m_animTime = 0.0;
        if (m_x <= -2.0 || m_x >= 2.0) m_xoffset = -m_xoffset; // toggle xoffset
    }

    g_drawScale = 1.0;
    DrawLine(-g_width / 2, 0, g_width / 2, 0, '.');
    DrawLine(0, -g_height / 2, 0, g_height / 2, '.');

    DrawFunction(&SquareFunction, -20.0, +20.0, 1, '*');

    const double dx = 0.001;
    double y = SquareFunction(m_x);
    double diff = NewtonsDifference(&SquareFunction, m_x, dx);
    //double diff = SymmetricDifference(&SquareFunction, x, dx);

    //g_drawScale = 20;
    //DrawFunction2(&ExpFunction, base_, -10.0, +10.0, 0.1, 'e');
    //DrawFunction2(&LogFunction, base_, 0.0001, +10.0, 0.1, 'l');
    //DrawFunction(&SineFunction, -5.0, +5.0, 0.1, 's');
    //DrawFunction(&AsineFunction, -1.0, +1.0 - 0.0001, 0.1, 'a');
    //g_drawScale = 1.0;

    {
        const double dx = 0.001;
        double y = SquareFunction(m_x);
        double diff = SymmetricDifference(&SquareFunction, m_x, dx);

        KVector2 v0 = KVector2(m_x, y);
        KVector2 vdir = KVector2(dx, diff * dx);
        vdir.Normalize();

        DrawLine(v0, v0 + vdir * 20.0, 'o');
        DrawLine(v0, v0 + vdir * -20.0, 'o');
    }

    char buffer[80];
    sprintf_s(buffer, sizeof(buffer), "%g", elapsedTime);
    PutText(0, 0, buffer);
}
