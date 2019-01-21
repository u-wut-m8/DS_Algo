#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int T, N, X, *arr, flag, xind;
	std::cin>>T;
	while(T--) {
	    flag = 0;
	    std::cin>>N>>X;
        xind = N-1;
	    arr = new int[N];
	    for(int i=0;i<N;i++)
	        std::cin>>arr[i];
        std::sort(arr, arr+N);
        for(int i=0;i<N;i++)
	        if(arr[i] >= X){
	            xind = i-1;
	            break;
	        }
        for(int i=0, j=xind;i<j;)
            if(arr[i] + arr[j] == X) {
                flag = 1;
                break;
            }
            else if (arr[i] + arr[j] < X)
                i++;
            else
                j--;
        if(flag)
            std::cout<<"Yes"<<std::endl;
        else
            std::cout<<"No"<<std::endl;
        delete[] arr;
    }
    return 0;
}
