#include <iostream>
#include <vector>
#include <algorithm>

int compare(std::string a, std::string b) {
    std::string ab = a.append(b);
    std::string ba = b.append(a);
    return ab.compare(ba) > 0 ? 1 : 0;
}

void printLargest(std::vector<std::string> v) {
    std::sort(v.begin(), v.end(), compare);
    for(auto it=v.begin();it!=v.end();++it)
        std::cout<<(*it);
    std::cout<<std::endl;
}

int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::vector<std::string> arr = {"54", "546", "548", "60"};
    printLargest(arr);
    return 0;
}
