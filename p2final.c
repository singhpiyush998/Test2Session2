/*
Write a program to find whether the three points form a triangle.
void input_triangle(float *x1, float *y1, float *x2, float *y2, float *x3, float *y3);
int is_triangle(float x1, float y1, float x2, float y2,float x3, float y3)
void output(float x1, float y1, float x2, float y2,float x3, float y3, int istriangle)
*/

#include <stdio.h>
#include <math.h>

void input_triangle(float* x1, float* y1, float* x2, float* y2, float* x3, float* y3)
{
    printf("enter the coordinated of 3 points:\n");
    scanf("%f%f%f%f%f%f", x1, y1, x2, y2, x3, y3);
}


/*
1 - Triangle
0 - Not triangle
*/
int is_triangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
    float area = 0.5 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    return fabs(area) > 0;
}

void output(float x1, float y1, float x2, float y2, float x3, float y3, int istriangle)
{
    if (istriangle)
        printf("The points (%f, %f), (%f,%f) and (%f,%f) form a triangle\n", x1, y1, x2, y2, x3, y3);
    else
        printf("The points (%f, %f), (%f,%f) and (%f,%f) do not form a triangle\n", x1, y1, x2, y2, x3, y3);
}

int main()
{
    float x1, y1, x2, y2, x3, y3;
    input_triangle(&x1, &y1, &x2, &y2, &x3, &y3);
    int res = is_triangle(x1, y1, x2, y2, x3, y3);
    output(x1, y1, x2, y2, x3, y3, res);
    return 0;
}