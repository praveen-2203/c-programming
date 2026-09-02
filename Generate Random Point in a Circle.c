#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef struct {
    double radius;
    double x_center;
    double y_center;
} Solution;

double getRand() {
    return (double)rand() / (double)RAND_MAX;
}

Solution* solutionCreate(double radius, double x_center, double y_center) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));
    obj->radius = radius;
    obj->x_center = x_center;
    obj->y_center = y_center;
    return obj;
}

double* solutionRandPoint(Solution* obj, int* returnSize) {
    *returnSize = 2;
    double* result = (double*)malloc(2 * sizeof(double));
    
    // Core math transformations to guarantee uniformity across the circle area
    double len = obj->radius * sqrt(getRand());
    double deg = getRand() * 2.0 * M_PI;
    
    result[0] = obj->x_center + len * cos(deg);
    result[1] = obj->y_center + len * sin(deg);
    
    return result;
}

void solutionFree(Solution* obj) {
    free(obj);
}
