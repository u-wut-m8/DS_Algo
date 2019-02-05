#include <iostream>

int main(int argc, char *argv[]) {
    short T, P, Q, p, c;
    std::cin>>T;
    while(T--) {
        std::cin>>P>>Q;
        p = 0;
        c = 0;
        while(P > 1 || Q > 1){
            if(P>Q){
                P >>= 1;
                Q = P;
            }else{
                Q >>= 1;
                P = Q;
            }
            p = (p == 0) ? 1 : 0;
            c++;
        }
        if(p == 0)
            std::cout<<"Jeel"<<std::endl;
        else
            std::cout<<"Ashish"<<std::endl;
    }
    return 0;
}