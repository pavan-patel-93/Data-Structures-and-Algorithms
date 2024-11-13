#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;  // n is the number of vertices, m is the number of edges

    // Initialize the adjacency matrix with zeros
    vector<vector<int>> adj(n+1, vector<int>(n+1, 0));

    // Input the edges and update the adjacency matrix
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; 
    }

    // Print the adjacency matrix
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
