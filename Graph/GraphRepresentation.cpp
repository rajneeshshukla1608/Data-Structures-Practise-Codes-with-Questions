//Graph representation in c++ with adjacency list and adjacency graph with weighted, connected, undirested 
// and directed graph as well

#include<bits/stdc++.h>
using namespace std;

// Using the adjacency matrix  for connected undirected graph
void adjacencyMatrix(int nodes, int edges) {
    vector<pair<int, int>> direction;
    int adjmatrix[nodes + 1][nodes +1 ];
    for (int index = 0; index < edges; index++){
        int u, v;
        cin >> u >> v;
        direction.push_back({u, v}); // method 1 similarly do the second
        direction[index].second = v; // method 2 similarly do the first
        adjmatrix[u][v] = 1;
        adjmatrix[v][u] = 1; // just remove this line for the directed graph
    }
    for (int index = 0; index < edges; index++)
    {
        cout << "From: " << direction[index].first;
        cout << "To: " << direction[index].second<< "\n";
    }

}
//Using the adjacency matrix ends here


// Using the adjacency list  for connected undirected graph
//using the adjacency list starts here
void adjacencyList(int nodes, int edges) {
    vector<int> adjlist[nodes + 1];
    vector<pair<int, int>> direction;
    for (int index = 0; index < edges; index++)
    {
        int u, v;
        cin>> u >> v;
        direction.push_back({u, v}); // method 1 similarly do the second
        direction[index].second = v; // method 2 similarly do the first
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);   // just remove this line for directed graph
    }
    for (int index = 0; index < edges; index++)
    {
        cout << "From: " << direction[index].first;
        cout << "To: " << direction[index].second<< "\n";
    }
}
// using the adjacency list endes here

// adjacency list with connected weighted directed graph:

void adjacencylistwithweight(int nodes, int edges){
    vector<pair<int,int>> adjlist[nodes + 1];
    for (int index = 0; index < edges; index++)
    {
        int u, v, weight;
        cin>> u >> v >> weight;
        adjlist[u].push_back({v,weight});
        adjlist[v].push_back({u, weight});   // just remove this line for directed graph
    }
}

// Driver Code
int main() {
    int nodes, edges;
    cin >> nodes>> edges;
    // adjacencyList(nodes, edges);
    // adjacencyMatrix(nodes, edges); 
    adjacencylistwithweight(nodes, edges);
    return 0;
}