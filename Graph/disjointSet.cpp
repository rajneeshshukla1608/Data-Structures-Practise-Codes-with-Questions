#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n+1, 0); // intialization of rank array to be all 0 and n + 1 because it 1 based indexing;
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i; // everyone is parent of itself;
        }
    }

    int findUpar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findUpar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        } else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unioBySize(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};



int main() {
    DisjointSet ds(7);
    // ds.unionByRank(1, 2);
    // ds.unionByRank(2, 3);
    // ds.unionByRank(4, 5);
    // ds.unionByRank(6, 7);
    // ds.unionByRank(5, 6);

    ds.unioBySize(1, 2);
    ds.unioBySize(2, 3);
    ds.unioBySize(4, 5);
    ds.unioBySize(6, 7);
    ds.unioBySize(5, 6);

    // if 3 and 7 belog to rthe same component;
    if(ds.findUpar(3) == ds.findUpar(7)) {
        cout << "same"<< "\n";
    } else cout << "not same" << "\n";

    ds.unioBySize(3, 7);

    if(ds.findUpar(3) == ds.findUpar(7)) {
        cout << "same"<< "\n";
    } else cout << "not same" << "\n";
    return 0;
}