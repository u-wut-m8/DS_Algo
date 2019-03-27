//Time Complexity: O((V+E)logV)

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

const int MAX = 1e4 + 5;
bool marked[MAX];
std::vector<std::pair<long long, int>> adj[MAX];

long long prim(int x) {
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> q;
    int y;
    long long minimumCost = 0;
    std::pair<long long, int> p;
    q.push(std::make_pair(0, x));
    while(!q.empty()) {
        p = q.top();
        q.pop();
        x = p.second;
        if(marked[x])
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i=0;i<adj[x].size();i++){
            y = adj[x][i].second;
            if(!marked[y])
                q.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main(int argc, char* argv[]) {
    int nodes, edges, x, y;
    long long weight, minimumCost;
    std::cin>>nodes>>edges;
    for(int i=0;i<edges;i++) {
        std::cin>>x>>y>>weight;
        adj[x].push_back(std::make_pair(weight, y));
        adj[y].push_back(std::make_pair(weight, x));
    }
    minimumCost = prim(1);
    std::cout<<minimumCost<<std::endl;
    return 0;
}