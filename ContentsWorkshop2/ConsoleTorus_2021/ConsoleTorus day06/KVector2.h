#pragma once
class KVector2
{
public:
    double  x = 0.0;
    double  y = 0.0;

public:
    KVector2( double tx = 0.0, double ty=0.0);
    ~KVector2();
};

inline KVector2 operator+(KVector2 lhs, KVector2 rhs) {
    KVector2 t;
    t.x = lhs.x + rhs.x;
    t.y = lhs.y + rhs.y;
    return t;
}

inline KVector2 operator*(double s, KVector2 rhs) {
    KVector2 t;
    t.x = s * rhs.x;
    t.y = s * rhs.y;
    return t;
}

inline KVector2 operator*( KVector2 lhs, double s) {
    KVector2 t;
    t.x = s * lhs.x;
    t.y = s * lhs.y;
    return t;
}