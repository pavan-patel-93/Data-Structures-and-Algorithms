#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // DFS to explore all connected nodes (province)
    void dfs(int node, vector<int> adj[], vector<int>& visited){
        visited[node] = 1;  // Mark the current node as visited
        for(auto it: adj[node]){  // Explore adjacent nodes
            if(!visited[it]){
                dfs(it, adj, visited);  // Recursive DFS call for unvisited nodes
            }
        }
    }

    // Function to return the number of provinces (connected components)
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();  // Number of nodes (cities)
        vector<int> adjList[V];  // Adjacency list for graph representation

        // Construct adjacency list from the given isConnected matrix
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(isConnected[i][j] == 1 && i != j){  // If there's a direct connection between city i and city j
                    adjList[i].push_back(j);  // Add j to i's adjacency list
                    adjList[j].push_back(i);  // Add i to j's adjacency list (undirected graph)
                }
            }
        }

        int count = 0;  // To count the number of provinces
        vector<int> visited(V, 0);  // Visited array to track visited nodes (cities)

        // Perform DFS for each unvisited city
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs(i, adjList, visited);  // Perform DFS for unvisited city
                count++;  // Each DFS call represents one connected component (province)
            }
        }
        return count;  // Return the number of provinces
    }
};

int main() {
    // Input number of test cases
    int t;
    cin >> t;
    
    while (t--) {
        // Input the number of cities (V)
        int V;
        cin >> V;

        // Input the adjacency matrix representing the connected cities
        vector<vector<int>> isConnected(V, vector<int>(V));
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cin >> isConnected[i][j];
            }
        }

        // Create a Solution object and find the number of provinces
        Solution obj;
        int result = obj.findCircleNum(isConnected);
        
        // Output the result
        cout << result << endl;
    }

    return 0;
}
