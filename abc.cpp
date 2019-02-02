#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int main(int argc, char const *argv[])
{
	int T, N, *arr, *temp, max, k;
	std::cin>>T;
	while(T--) {
        std::cin>>N;
        arr = new int[N];
        max = INT_MIN;
        for(int i=0;i<N;i++){
            std::cin>>*(arr+i);
            if(arr[i] > max)
                max = arr[i];
        }
        temp = new int[max+1];
        for(int i=0;i<=max;i++)
            temp[i] = 0;
        for(int i=0;i<N;i++)
            temp[arr[i]]++;
        int ind;
        for(int i=0;i<=max;i++)
            if(temp[i] > 0){
                ind = i;
                break;
            }
        k = INT_MIN;
        for(int i=ind+1;i<=max;i++)
            if(temp[i] > 0 && std::abs(ind-i) > k){
                    k = std::abs(ind-i);
                    ind = i;
                }
        std::cout<<k<<std::endl;
        delete[] temp;
        delete[] arr;
	}
    return 0;
}
