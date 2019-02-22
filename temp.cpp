#include <iostream>
#include <climits>

int main() {
    int T, N, *arr, one_count, sum, total;
    std::cin>>T;
    while(T--){
        std::cin>>N;
        arr = new int[N];
        one_count = 0;
        for(int i=0;i<N;i++){
            std::cin>>*(arr+i);
            if(*(arr+i))
                one_count++;
        }
        for(int i=0;i<N;i++)
            *(arr+i) = *(arr+i)&1 ? -1 : 1;
        total = SHRT_MIN;
        sum = 0;
        for(int i=0;i<N;i++){
            sum += *(arr+i);
            if(total < sum)
                total = sum;
            if(sum < 0)
                sum = 0;
        }
        std::cout<<one_count+total<<std::endl;
        delete[] arr;
    }
	return 0;
}