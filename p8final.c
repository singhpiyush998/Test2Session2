/*
. Write a program to find the permeter of a polygon
struct _point {
float x,y;
};
typedef struct _point Point;
struct _line
{
Point p1,p2;
float distance;
};
struct _line Line;
struct _polygon {
int n;
Line l[100];
float perimenter;
}
int input_n();
int input_polygon( int n, Polygon *p);
Line input_line();
void input_n_lines(int n, Line l[n]);
void find_perimeter(Polygon *p);
void output(Polygon p);
*/

#include <stdio.h>
#include <math.h>

typedef struct point
{
    float x, y;
} Point;

typedef struct line
{
    Point p1, p2;
    float distance;
} Line;

typedef struct polygon
{
    int sides;
    Line l[100];
    float perimeter;
} Polygon;

int input_n()
{
    int sides;
    printf("Enter the sides of a polygon: ");
    scanf("%d", &sides);
    return sides;
}

Point input_point()
{
    Point p;
    scanf("%f%f", &p.x, &p.y);
    return p;
}

Line input_line()
{
    Line l;
    printf("Enter the first point:\n");
    l.p1 = input_point();
    printf("Enter the second point:\n");
    l.p2 = input_point();
    return l;
}

void input_n_lines(int n, Line* l)
{
    for (int i = 0; i < n; i++)
    {
        printf("Line number %d\n", i + 1);
        l[i] = input_line();
    }
}

int input_polygon(Polygon* p)
{
    p->sides = input_n();
    input_n_lines(p->sides, p->l);
}

void find_length(Line* l)
{
    l->distance = sqrt((l->p1.x - l->p2.x) * (l->p1.x - l->p2.x) + (l->p1.y - l->p2.y) * (l->p1.y - l->p2.y));
}


void find_n_lengths(int n, Line* l)
{
    for (int i = 0; i < n; i++)
    {
        find_length(&l[i]);
    }
}

void find_perimeter(Polygon* p)
{
    find_n_lengths(p->sides, p->l);
    p->perimeter = 0;
    for (int i = 0; i < p->sides; i++)
    {
        p->perimeter += p->l[i].distance;
    }
}

void output(Polygon p)
{
    printf("The perimeter of given polygon is: %.2f\n", p.perimeter);
}

int main()
{
    Polygon p;
    input_polygon(&p);
    find_perimeter(&p);
    output(p);
    return 0;
}
