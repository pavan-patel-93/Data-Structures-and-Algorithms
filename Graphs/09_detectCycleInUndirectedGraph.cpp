#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
        /**
         * Detecting of cycle using BFS
         */
        bool detectCycleUsingBFS(int src, vector<vector<int>>& adj, vector<int>& visited){
            queue<pair<int, int>> q;
            // node, source --> from where the node came from;
            q.push({src, -1});
            visited[src] = 1;
            while(!q.empty()){
                int node = q.front().first;
                int parent = q.front().second;

                q.pop();

                for(auto adjNode: adj[node]){
                    if(!visited[adjNode]){
                        q.push({adjNode, node});
                        visited[adjNode] = 1;
                    }else if(parent != adjNode){
                        // If adjNode is not the parent of the current node (node), 
                        // it means this adjNode was visited earlier through a different path.
                        // This confirms a cycle because there is another way to reach this already visited node.
                        return true;
                    }
                }  


            }
            return false;
        }

        /**
         * Detecting of cycle using DFS
         */
        bool detectCycleUsingDFS(int node, int parent, vector<vector<int>>& adj, vector<int>& visited){
           
            visited[node] = 1;
            for(auto adjNode: adj[node]){
                if(!visited[adjNode]){
                    if(detectCycleUsingDFS(adjNode, node, adj, visited)) return true;
                }else if (adjNode != parent){
                    return true;
                }
            }
            return false;
        }
    public:
        bool hasCycle(vector<vector<int>>& adj){
            int n = adj.size();
            vector<int> visited(n, 0);
            for(int i=0 ; i<n ; i++){
                if(!visited[i]){
                    // if(detectCycleUsingBFS(i, adj, visited)) return true;
                    if(detectCycleUsingDFS(i, -1, adj, visited)) return true;
                }
            }
            return false;
        }
};

int main() {
    int n = 7;
    vector<vector<int>> adj(n+1);
    /**
     *      2-----5
     *     /       \
     *    1         7
     *     \       /
     *      3-----6
     *      |
     *      2
     */

    adj[1].push_back(2);
    adj[1].push_back(3);

    adj[2].push_back(5);
    adj[2].push_back(1);
    
    adj[3].push_back(1);
    adj[3].push_back(6);
    adj[3].push_back(4);

    adj[4].push_back(3);

    adj[5].push_back(2);
    adj[5].push_back(7);

    adj[6].push_back(3);
    adj[6].push_back(7);

    adj[7].push_back(5);
    adj[7].push_back(6);

    Solution sol;
    bool isCycle = sol.hasCycle(adj);
    cout << ( isCycle ? "The graph has cycle" : "The graph does not have a cycle" ) << endl;

    return 0;
}
