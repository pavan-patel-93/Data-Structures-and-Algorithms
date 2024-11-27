#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
        /**
         * Detecting of cycle using DFS
         */
        bool detectCycleUsingDFS(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathVisited){
            visited[node] = 1;
            pathVisited[node] = 1;

            for(auto it: adj[node]){
                if(!visited[it]){
                    if(detectCycleUsingDFS(it, adj, visited, pathVisited)) return true;
                }else{
                    // If the node has been previously visited but it has to be be visited on the same path
                    if(pathVisited[it]){
                        return true;
                    }
                }
            }

            pathVisited[node] = 0; // while moving backwards, making nodes as not path visited
            return false;
        }
    public:
        bool hasCycle(vector<vector<int>>& adj){
            int n = adj.size();
            vector<int> visited(n, 0);
            vector<int> pathVisited(n, 0);

            for(int i=0 ; i<n ; i++){
                if(!visited[i]){
                    if(detectCycleUsingDFS(i, adj, visited, pathVisited)) return true;
                }
            }
            return false;
        }
};

int main() {
    int n = 10;
    vector<vector<int>> adj(n+1);
    /**
     *      1--> 2 -------> 3 --> 4
     *           ^          |     |
     *           |          v     v
     *           8 <--10    7 --> 5 --> 6
     *           \>   />
     *              9
     */

    adj[1].push_back(2);  // 1 -> 2

    adj[2].push_back(3);  // 2 -> 3

    adj[3].push_back(4);  // 3 -> 4
    adj[3].push_back(7);  // 3 -> 7

    adj[4].push_back(5);  // 4 -> 5

    adj[5].push_back(6);  // 5 -> 6

    adj[7].push_back(5);  // 7 -> 5

    adj[8].push_back(2);  // 8 -> 2 (cycle)
    adj[8].push_back(9);  // 8 -> 9

    adj[9].push_back(10); // 9 -> 10

    adj[10].push_back(8); // 10 -> 8 (cycle)

    Solution sol;
    bool isCycle = sol.hasCycle(adj);
    cout << ( isCycle ? "The graph has cycle" : "The graph does not have a cycle" ) << endl;

    return 0;
}
