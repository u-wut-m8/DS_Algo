#include <iostream>
using namespace std;

struct point {
    int x, y;
};

int main() {
	//code
	int T;
	std::cin>>T;
	while(T--) {
	    point l1, r1, l2, r2;
	    std::cin>>l1.x>>l1.y>>r1.x>>r1.y;
	    std::cin>>l2.x>>l2.y>>r2.x>>r2.y;
        if(r1.y==r2.y && r2.x==l1.x && l2.y==l1.y)
            std::cout<<"1\n";
        else if(r1.x==r2.x && l1.y==r2.y && l2.x==l1.x)
            std::cout<<"1\n";
        else if(l2.x==r1.x && l2.y==l1.y && r2.y==r1.y)
            std::cout<<"1\n";
        else if(l2.x==l1.x && l2.y==r1.y && r2.x==r1.x)
            std::cout<<"1\n";
        else if(l2.x>=r1.x || l1.x>=r2.x || l2.y<=r1.y || l1.y<=r2.y)
            std::cout<<"0\n";
        else 
            std::cout<<"1\n";
	}
	return 0;
}