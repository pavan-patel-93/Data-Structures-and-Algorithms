#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
   void dfs(int i, vector<vector<int>>& adj, int V, vector<bool>& vis, vector<int>& res) {
        if (vis[i])
            return;

        // marking vertex as visited and adding it to output list.
        vis[i] = true;
        res.push_back(i);

        for (int j : adj[i]) {
            if (!vis[j])
                dfs(j, adj, V, vis, res);
        }
    }

    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<bool> vis(V, false); 

        vector<int> res;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, V, vis, res);
            }
        }
        return res;
    }
};


int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
