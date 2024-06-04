#include <array>
#include "vector3d.h"


struct Color {
    double r, g, b;
};


struct Face : public std::vector<size_t> {
    Face(size_t size) : color{0,0,0} {
        resize(size);
    }
    Color color;
};

struct Point2D {
    double x, y;
};


template <typename T>
struct Figure {
    std::vector<T*> points;
    std::vector<Face> faces;
};

using Figure2D = Figure<Point2D>;
using Figure3D = Figure<Vector3D>;
