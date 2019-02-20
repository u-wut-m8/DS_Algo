#include <iostream>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    short T, N, K, *arr;
    std::map<int, int> mp;
    std::cin>>T;
    while(T--){
        std::cin>>N>>K;
        arr = new short[N];
        for(short i=0;i<N;i++)
            std::cin>>*(arr+i);
        for(short i=0;i<K;i++)
            mp[arr[i]]++;
        std::cout<<mp.rbegin()->first<<' ';
        short c = 0;
        for(short i=K;i<N;i++){
            mp[arr[c++]]--;
            mp[arr[i]]++;
            std::cout<<mp.rbegin()->first<<' ';
        }
        std::cout<<std::endl;
        delete[] arr;
    }
	return 0;
}