#include <iostream>
#include <climits>

int maxSubArray(int *arr, int size) {
    int sum = 0, total = INT_MIN;
    int start = 0, end = 0, s = 0;
    for(int i=0;i<size;i++) {
        sum += arr[i];
        if(total < sum) {
            total = sum;
            start = s;
            end = i;
        }
        if(sum < 0) {
            sum = 0;
            s = i+1;
        }
    }
    std::cout<<start<<" "<<end<<std::endl;
    return total;
}

int main() {
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    std::cout<<maxSubArray(a, 8)<<std::endl;
    return 0;
}