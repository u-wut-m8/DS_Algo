#include <iostream>
#include <map>
#include <vector>

void solve(int num, int den) {
    std::cout<<num/den;
    if(num%den == 0)
        return;
    std::cout<<".";
    std::map<int, int> mp;
    std::vector<int> v;
    int rem = num%den;
    mp[rem] = 0;
    int mpInd = 1, same = -1;
    while(rem > 0){
        rem *= 10;
        v.push_back(rem/den);
        rem %= den;
        if(mp.find(rem) != mp.end()){
            same = mp[rem];
            break;
        }
        mp[rem] = mpInd++;
    }
    if(same == -1)
        for(int val : v)
            std::cout<<val;
    else{
        for(int i=0;i<same;i++)
            std::cout<<v[i];
        std::cout<<'(';
        for(int i=same;i<v.size();i++)
            std::cout<<v[i];
        std::cout<<')';
    }
    mp.clear();
    v.clear();
}

int main(int argc, char *argv[]) {
    int T, N, D;
    std::cin>>T;
    while(T--) {
        std::cin>>N>>D;
        solve(N, D);
        std::cout<<std::endl;
    }
    return 0;
}