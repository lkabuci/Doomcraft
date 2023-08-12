//
// Created by redone on 8/3/23.
//

#include "vector.h"

t_vector v_new(double x, double y)
{
    t_vector v;
    v.x = x;
    v.y = y;
    return v;
}

double v_magnitude(t_vector v)
{
    return sqrt(v.x * v.x + v.y * v.y);
}

t_vector v_normalize(t_vector v)
{
    double magnitude = v_magnitude(v);
    return v_new(v.x / magnitude, v.y / magnitude);
}
