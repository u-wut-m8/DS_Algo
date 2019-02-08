#include <iostream>

struct Point {
    int x, y;
};

int orientation(Point p1, Point p2, Point p3) {
    int val = (p2.y - p1.y)*(p3.x - p2.x) - (p3.y - p2.y)*(p2.x - p1.x);
    return (val == 0) ? 0 : (val < 0) ? -1 : 1;
}

bool onSegment(Point p, Point q, Point r) {
    if(q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&                     //q.x lies between p.x and r.x
       q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y))                       //q.y lies between p.y and r.y
       return true;
    return false;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if(o1 != o2 && o3 != o4)                //General case
        return true;
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if(o1 == 0 && onSegment(p1, p2, q1)) return true;
    // p1, q1 and q2 are colinear and q2 lies on segment p1q1
    if(o2 == 0 && onSegment(p1, q2, q1)) return true;
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if(o3 == 0 && onSegment(p2, p1, q2)) return true;
    // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if(o4 == 0 && onSegment(p2, q1, q2)) return true;
    return false;
}

int main(int argc, char* argv[]) {
    Point p1 = {1, 1}, q1 = {10, 1}; 
    Point p2 = {1, 2}, q2 = {10, 2};
    doIntersect(p1, q1, p2, q2)? std::cout << "Yes\n": std::cout << "No\n"; 
  
    p1 = {10, 0}, q1 = {0, 10}; 
    p2 = {0, 0}, q2 = {10, 10}; 
    doIntersect(p1, q1, p2, q2)? std::cout << "Yes\n": std::cout << "No\n"; 
  
    p1 = {-5, -5}, q1 = {0, 0}; 
    p2 = {1, 1}, q2 = {10, 10}; 
    doIntersect(p1, q1, p2, q2)? std::cout << "Yes\n": std::cout << "No\n"; 
    return 0;
}