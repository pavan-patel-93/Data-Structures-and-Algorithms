#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;  // n is the number of vertices, m is the number of edges

    // Create an adjacency list (vector of vectors)
    vector<vector<int>> adj(n+1);

    // Input the edges and populate the adjacency list
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Since the graph is undirected
    }

    // Print the adjacency list
    for(int i = 1; i <= n; i++){
        cout << "Vertex " << i << ": ";
        for(int neighbor : adj[i]){
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}
