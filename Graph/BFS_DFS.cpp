#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define MAX 100000

bool visited_bfs[MAX];
bool visited_dfs[MAX];

void BFS(int s, std::vector<int>* v) {
    std::queue<int> q;
    q.push(s);
    visited_bfs[s] = true;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(int i=0;i<v[p].size();i++)
            if(!visited_bfs[v[p][i]]){
                q.push(v[p][i]);
                visited_bfs[v[p][i]] = true;
                std::cout<<v[p][i]<<' ';
            }
    }
    std::cout<<std::endl;
}

void dfs_iterative(int s, std::vector<int>* v) {
    std::stack<int> st;
    st.push(s);
    visited_dfs[s] = true;
    while(!st.empty()){
        int p = st.top();
        st.pop();
        for(int i=0;i<v[p].size();i++)
            if(!visited_dfs[v[p][i]]){
                st.push(v[p][i]);
                visited_dfs[v[p][i]] = true;
                std::cout<<v[p][i]<<' ';
            }
    }
    std::cout<<std::endl;
}

void dfs_recursive(int s, std::vector<int>* v) {
    visited_dfs[s] = true;
    std::cout<<s<<' ';
    for(int i=0;i<v[s].size();i++)
        if(!visited_dfs[v[s][i]])
            dfs_recursive(v[s][i], v);
}

int main(int argc, char* argv[]) {
    int N, x, y;
    std::vector<int> adj[MAX];
    std::cin>>N;
    for(int i=0;i<N-1;i++){
        std::cin>>x>>y;
        adj[x].push_back(y);                    //Undirected graph
        adj[y].push_back(x);
    }
    BFS(1, adj);
    dfs_iterative(1, adj);
    return 0;
}