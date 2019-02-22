/*
You are given an array A[] of size N. Now, we call the value of an array the bit-wise XOR of all elements it contains. 
For example, the value of the array [1,2,3] = 1^2^3. Now, Your task is to find the bit-wise XOR of the values of all sub arrays of array A. 

Example:
Input: A[] = {1,2,3} 
Output: 2
xor[1] = 1, 
xor[1, 2] = 3
xor[2, 3] = 1
xor[1, 2, 3] = 0
xor[2] = 2
xor[3] = 3
Result : 1 ^ 3 ^ 1 ^ 0 ^ 2 ^ 3 = 2
*/

#include <iostream>

int main() {
    int T, N, *arr, temp;
    std::cin>>T;
    while(T--){
        std::cin>>N;
        arr = new int[N];
        for(int i=0;i<N;i++)
            std::cin>>arr[i];
        /*
        If N is even all elements of array will repeat themselves even number of times, 
        otherwise alternate elements will repeat even and odd times.
        */    
        if(!(N&1)){                                                             
            std::cout<<0<<std::endl;
            delete[] arr;
            continue;
        }
        temp = 0;
        for(int i=0;i<N;i+=2)
            temp ^= arr[i];
        std::cout<<temp<<std::endl;
        delete[] arr;
    }
	return 0;
}