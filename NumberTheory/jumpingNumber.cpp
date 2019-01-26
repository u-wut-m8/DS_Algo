#include <iostream>
#include <vector>
#include <algorithm>

void jumpingNumber(long long num) {
    std::vector<long long> t;
    std::vector<long long> v;
    t.push_back(0);
    for(int i=1;i<=9;i++){
        v.push_back(i);
        while(!v.empty()){
            long long temp = v[v.size()-1];
            v.pop_back();
            if(temp > num)
                continue;
            t.push_back(temp);
            long long left = temp%10;
            if(left > 0)
                v.push_back(temp*10 + (left-1));
            if(left < 9)
                v.push_back(temp*10 + (left+1));
        }
    }
    std::sort(t.begin(), t.end());
    for(std::vector<long long>::iterator it=t.begin();it!=t.end();++it)
        std::cout<<(*it)<<" ";
    std::cout<<std::endl;
}

int main(int argc, char const *argv[])
{
    int T;
    long long N;
    std::cin>>T;
    while(T--) {
        std::cin>>N;
        jumpingNumber(N);
    }
    return 0;
}
