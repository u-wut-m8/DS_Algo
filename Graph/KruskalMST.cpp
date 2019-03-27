#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

const int MAX = 1e4 + 5;
int id[MAX], nodes, edges;
std::pair<long long, std::pair<int, int>> p[MAX];

void initialize() {
    for(int i=0;i<MAX;i++)
        id[i] = i;
}

int root(int i) {
    while(id[i] != i) {
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

void set_union(int x, int y) {
    int root_X = root(x);
    int root_Y = root(y);
    id[root_X] = id[root_Y];
}

long long kruskal(std::pair<long long, std::pair<int, int>>* p) {
    int x, y;
    long long cost, minimumCost = 0;
    for(int i=0;i<edges;i++){
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x) != root(y)){
            minimumCost += cost;
            set_union(x, y);
        }
    }
    return minimumCost;
}

int main(int argc, char* argv[]) {
    int x, y;
    long long weight, cost, minimumCost;
    initialize();
    std::cin>>nodes>>edges;
    for(int i=0;i<edges;i++){
        std::cin>>x>>y>>weight;
        p[i] = std::make_pair(weight, std::pair<int, int>{x, y});
    }
    std::sort(p, p+edges);
    minimumCost = kruskal(p);
    std::cout<<minimumCost<<std::endl;
    return 0;
}