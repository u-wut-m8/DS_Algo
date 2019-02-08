#include <iostream>

/*
If orientation of (p1, p2, p3) is collinear, then orientation of (p3, p2, p1) is also collinear.
If orientation of (p1, p2, p3) is clockwise, then orientation of (p3, p2, p1) is counterclockwise and vice versa is also true.
The idea is to use slope.

Slope of line segment (p1, p2): σ = (y2 - y1)/(x2 - x1)
Slope of line segment (p2, p3): τ = (y3 - y2)/(x3 - x2)

If  σ < τ, the orientation is counterclockwise (left turn)
If  σ = τ, the orientation is collinear
If  σ > τ, the orientation is clockwise (right turn)

Using above values of σ and τ, we can conclude that, 
the orientation depends on sign of  below expression: 

(y2 - y1)*(x3 - x2) - (y3 - y2)*(x2 - x1)

Above expression is negative when σ < τ, i.e., counterclockwise
Above expression is 0 when σ = τ, i.e., collinear
Above expression is positive when σ > τ, i.e., clockwise
*/

struct Point {
    int x, y;
};

inline int orientation(Point p1, Point p2, Point p3) {
    int val = (p2.y - p1.y)*(p3.x - p2.x) - (p3.y - p2.y)*(p2.x - p1.x);
    return (val == 0) ? 0 : (val < 0) ? -1 : 1;
}

int main(int argc, char* argv[]) {
    Point p1 = {0, 0}, p2 = {4, 4}, p3 = {1, 2};
    int ans = orientation(p1, p2, p3);
    if(!ans)
        std::cout<<"Colinear";
    else if(ans < 0)
        std::cout<<"Counter Clockwise";
    else
        std::cout<<"Clockwise";
    std::cout<<std::endl;
    return 0;
}