#pragma once
#include <array>
#include <list>
#include "vector3d.h"


struct Color {
    double r, g, b;
};

img::Color::Color(const ::Color& c)
:red(lround(c.r * 255))
,green(lround(c.g * 255))
,blue(lround(c.b * 255))
{}

struct Point2D {
    double x, y;
    void operator += (const Point2D& p){
        x += p.x;
        y += p.y;
    }
    Point2D operator + (Point2D p) const {
        p += *this;
        return p;
    }
    Point2D operator - () const {
        return {-x, -y};
    }
    void operator -= (const Point2D& p){
        *this += -p;
    }
    Point2D operator - (Point2D p) const {
        p -= *this;
        return p;
    }
};

struct Line2D {
    Point2D* p1;
    Point2D* p2;
    Color* color;
};

using Lines2D = std::list<Line2D*>;
