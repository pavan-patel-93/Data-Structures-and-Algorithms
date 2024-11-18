#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        visited[row][col] = 1;

        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int delRow = -1 ; delRow <= 1 ; delRow++){
                for(int delCol = -1 ; delCol <= 1 ; delCol++){
                    if(delRow == 0 && delCol == 0) continue;
                    int nRow = r + delRow;
                    int nCol = c + delCol;
                    if( nRow >= 0 && nRow < n &&
                        nCol >= 0 && nCol < m && 
                        !visited[nRow][nCol] &&
                        grid[nRow][nCol] == 1
                    ){
                        visited[nRow][nCol] = 1;
                        q.push({nRow, nCol});
                    }
                }
            }
            
        }
        
    }

public:
    int numberOfIslands(vector<vector<int>>& grid) {
        int v = grid.size();
        vector<int> adj[v];

        // Converting adjacency matrix to adjacency list
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (grid[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int numberOfIsl = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));


        // We need to traverse now,
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < m ; col++){
                if(!visited[row][col] && grid[row][col] == 1){
                    bfs(row, col, grid, visited);
                    numberOfIsl++;
                }
            }
        }

        return numberOfIsl;
    }
};

int main() {
    Solution solution;
    
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 1},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 0, 0},
    };
    
    int result = solution.numberOfIslands(grid);
    cout << "Number of islands " << result << endl;

    return 0;
}
