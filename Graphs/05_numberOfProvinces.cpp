#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void dfs(int node, vector<int> adj[], vector<int>& visited) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs(it, adj, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int> adj[v];

        // Converting adjacency matrix to adjacency list
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> visited(v, 0);
        int numberOfProvinces = 0;
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                numberOfProvinces++;
            }
        }
        return numberOfProvinces;
    }
};

int main() {
    Solution solution;
    
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    
    int result = solution.findCircleNum(isConnected);
    cout << "Number of provinces (connected components): " << result << endl;

    return 0;
}
