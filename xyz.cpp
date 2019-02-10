#include <iostream>
#include <algorithm>

int main() {
    short T, N, *a, *d, *temp;
    std::cin>>T;
    while(T--) {
        std::cin>>N;
        a = new short[N];
        d = new short[N];
        for(short i=0;i<N;i++)
            std::cin>>*(a+i);
        for(short i=0;i<N;i++)
            std::cin>>*(d+i);
        temp = new short[N];
        for(short i=0;i<N;i++)
            *(temp+i) = 0;
        for(short i=1;i<N-1;i++){
            if(d[i+1]-a[i] < d[i-1]-a[i])
                temp[i+1] += a[i];
            else
                temp[i-1] += a[i];
        }
        d[1]-a[0] < d[N-1]-a[0] ? temp[1] += a[0] : temp[N-1] += a[0];
        d[0]-a[N-1] < d[N-2]-a[N-1] ? temp[0] += a[N-1] : temp[N-2] += a[N-1];
        for(int i=0;i<N;i++)
            temp[i] = d[i]-temp[i];
        short val = *std::max_element(temp, temp+N);
        val <= 0 ? std::cout<<-1<<std::endl : std::cout<<val<<std::endl;
        delete[] temp;
        delete[] d;
        delete[] a;
    }
	return 0;
}