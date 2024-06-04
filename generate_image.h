#pragma once
#include <limits>
#include <cmath>
#include "easy_image.h"
#include "ini/ini_configuration.h"
#include "utils/base.hpp"


img::EasyImage draw2DLines(const Lines2D& lines, const int size){
    double xmin, ymin;
    xmin = ymin = std::numeric_limits<double>::infinity();
    double xmax, ymax;
    xmax = ymax = -std::numeric_limits<double>::infinity();

    double xrange = xmax - xmin;
    double yrange = ymax - ymin;

    double imagex = size * xrange / std::max(xrange, yrange);
    double imagey = size * yrange / std::max(xrange, yrange);

    double d = 0.95 * imagex / xrange;

    for (const auto& line : lines){
        line->p1->x *= d;
        line->p1->y *= d;
        line->p2->x *= d;
        line->p2->y *= d;
    }

    double DCx = d * (xmin + xmax) / 2;
    double DCy = d * (ymin + ymax) / 2;
    double dx = imagex / 2 - DCx;
    double dy = imagey / 2 - DCy;

    for (const auto& line : lines){
        line->p1->x += dx;
        line->p1->y += dy;
        line->p2->x += dx;
        line->p2->y += dy;
    }

    img::EasyImage image(lround(imagex), lround(imagey));
    for (const auto& line : lines){
        image.draw_line(lround(line->p1->x), lround(line->p1->y), lround(line->p2->x), lround(line->p2->y), img::Color(*line->color));
    }

    return {};
}

img::EasyImage LSystem2D(const ini::Configuration&);
