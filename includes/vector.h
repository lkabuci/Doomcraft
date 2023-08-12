//
// Created by redone on 8/3/23.
//

#ifndef CRAY_VECTOR_H
#define CRAY_VECTOR_H

#include "math.h"

typedef struct s_vector t_vector;
typedef struct s_point t_point;

struct s_vector {
    double x;
    double y;
};

struct s_point {
    int x;
    int y;
};

t_vector v_new(double x, double y);
double v_magnitude(t_vector v);
t_vector v_normalize(t_vector v);


#endif //CRAY_VECTOR_H
