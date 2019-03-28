#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <cstring>

#define SIZE 1000000+1

std::vector<std::pair<int, int>> v[SIZE];
int dist[SIZE];
bool visited[SIZE];

void djikstra() {
    memset(visited, false, sizeof(visited));
    dist[1] = 0;
    std::multiset<std::pair<int, int>> s;
    s.insert({0, 1});
    while(!s.empty()) {
        std::pair<int, int> p = *s.begin();
        s.erase(s.begin());
        int x = p.second, weight = p.first;
        if(visited[x])
            continue;
        visited[x] = true;
        for(int i=0;i<v[x].size();i++) {
            int e = v[x][i].first;
            int w = v[x][i].second;
            if(dist[x]+w<dist[e]){
                dist[e] = dist[x]+w;
                s.insert({dist[e], e});
            }
        }
    }
}

int main(int argc, char* argv[]) {
    int N, M;
    int x, y, w;
    std::cin>>N>>M;
    while(M--) {
        std::cin>>x>>y>>w;
        v[x].push_back({w, y});
    }
    djikstra();
    for(int i=2;i<=N;i++)
        std::cout<<dist[i]<<' ';
    std::cout<<std::endl;
    return 0;
}