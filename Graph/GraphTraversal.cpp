#include<bits/stdc++.h>
using namespace std;

// Bredth-First-Search(BFS) starts here
void  BFS(int nodes, vector<int> adjlist[]) {
    vector<int> bfs;
    vector<int> vis(nodes + 1, 0);

    for (int index = 1; index <= nodes; index++)
    {
        if(!vis[index]) {
            queue<int> q;
            q.push(index);
            vis[index] = 1;
            while (!q.empty()){
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for (auto it : adjlist[nodes]) {
                    if(!vis[it]) {
                        q.push(it); 
                        vis[it] = 1;
                    }
                }   
            }
        }
    }
    for(int it : bfs) {
        cout << it;
    }
}
// Bredth-First-Search(BFS) ends here


// Depth-First-Search(BFS) ends here
void dfs(int node, vector<int> &vis, vector<int> adjlist[], vector<int> &storedfs) {
    storedfs.push_back(node);
    vis[node] = 1;
    for(auto it : adjlist[node]){
        if(!vis[it]){
            dfs(it, vis, adjlist, storedfs);
        }
    }
}

void dfsOfGraph(int nodes, vector<int> adjlist[]) {
    vector<int> storedfs;
    vector<int> vis(nodes + 1, 0);
    for (int i = 1; i <= nodes; i++){
        if(!vis[i]) {
            dfs(i, vis, adjlist, storedfs);
        }
    }
    
    for(int i = 0; i < storedfs.size(); i++) {
        storedfs[i];
    }
}
// Depth-First-Search(BFS) ends here

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<int> adjlist[nodes + 1];

    for (int index = 0; index < edges; index++) 
    {
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    BFS(nodes, adjlist);
    dfsOfGraph(nodes, adjlist);
    return 0;
}