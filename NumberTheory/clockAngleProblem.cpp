#include <iostream>
#include <cmath>

int calcAngle(double h, double m) {
    if (h == 12)
        h = 0;
    if (m == 60)
        m = 0;
    std::cout<<0.5*(60*h + m)<<" "<<6.0*m<<std::endl;    
    float hr_angle = 0.5*(60*h + m);
    float min_angle = 6*m;
    std::cout<<hr_angle<<" "<<min_angle<<std::endl;
    double angle = std::fabs(hr_angle - min_angle);
    return (360-angle > angle) ? angle : 360-angle;
}

int main(int argc, char const *argv[])
{
    std::cout<<calcAngle(6, 28.7924)<<std::endl;
    return 0;
}
