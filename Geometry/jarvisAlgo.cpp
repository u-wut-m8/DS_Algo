#include <iostream>
#include <vector>

struct Point {
    int x, y;
};

inline int orientation(Point p1, Point p2, Point p3) {
    int val = (p2.y - p1.y)*(p3.x - p2.x) - (p3.y - p2.y)*(p2.x - p1.x);
    return (val == 0) ? 0 : (val < 0) ? -1 : 1;
}

/*
The idea of Jarvis’s Algorithm is simple, we start from the leftmost point (or point with minimum x coordinate value) 
and we keep wrapping points in counterclockwise direction. The big question is, given a point p as current point, 
how to find the next point in output? The idea is to use orientation() here. Next point is selected as the point 
that beats all other points at counterclockwise orientation, i.e., next point is q if for any other point r, 
we have “orientation(p, r, q) = counterclockwise”. Following is the detailed algorithm.

1) Initialize p as leftmost point.
2) Do following while we don’t come back to the first (or leftmost) point.
…..a) The next point q is the point such that the triplet (p, q, r) is counterclockwise for any other point r.
…..b) next[p] = q (Store q as next of p in the output convex hull).
…..c) p = q (Set p as q for next iteration).
*/

void convexHull(Point *points, int n) {
    if(n < 3)
        return;
    std::vector<Point> hull;
    int l = 0;
    // Find the leftmost point
    for(int i=1;i<n;i++)
        if(points[i].x < points[l].x)
            l = i;

    // Start from leftmost point, keep moving counterclockwise 
    // until reach the start point again.  This loop runs O(h) 
    // times where h is number of points in result or output.
    int p = l, q;
    do {
        // Add current point to result
        hull.push_back(points[p]);

        // Search for a point 'q' such that orientation(p, x, 
        // q) is counterclockwise for all points 'x'. The idea 
        // is to keep track of last visited most counterclock- 
        // wise point in q. If any point 'i' is more counterclock- 
        // wise than q, then update q. 
        q = (p+1)%n;
        for(int i=0;i<n;i++)
            if(orientation(points[p], points[i], points[q]) < 0)
                q = i;
        // Now q is the most counterclockwise with respect to p 
        // Set p as q for next iteration, so that q is added to 
        // result 'hull' 
        p = q;
    } while(p != l);     // While we don't come to first point
    
    for(std::vector<Point>::iterator it=hull.begin();it!=hull.end();++it)
        std::cout<<"("<<(*it).x<<", "<<(*it).y<<")"<<std::endl;
}

int main(int argc, char* argv[]) {
    Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, 
                      {3, 0}, {0, 0}, {3, 3}}; 
    int n = sizeof(points)/sizeof(points[0]); 
    convexHull(points, n);
    return 0;
}