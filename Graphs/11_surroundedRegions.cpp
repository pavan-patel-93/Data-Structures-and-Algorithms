#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> dx = {-1, +0, +1, +0};
    vector<int> dy = {+0, +1, +0, -1};
    private:
        void dfs(int row, int col, vector<vector<string>>& grid, vector<vector<int>>& visited){
            visited[row][col] = 1;
            int n = grid.size();
            int m = grid[0].size();
            for(int i=0 ; i<4 ; i++){
                int r = row + dx[i];
                int c = col + dy[i];

                if(
                    r >= 0 && r < n &&
                    c >= 0 && c < m &&
                    !visited[r][c] &&
                    grid[r][c] == "O"
                ) {
                    dfs(r, c, grid, visited);
                }
            }
        }
    public:
    void convertZerosToX(vector<vector<string>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(i==0 || j == 0 || i == n-1 || j == m-1){
                    if(!visited[i][j] && grid[i][j] == "O"){
                        dfs(i, j, grid, visited);
                    }
                }
            }
        }

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(!visited[i][j] && grid[i][j] == "O") grid[i][j] = "X";
            }
        }
    }
};

int main(){
    Solution sol;
    vector<vector<string>> grid = {
        {"X","X","X","X"},
        {"X","O","O","X"},
        {"X","X","O","X"},
        {"X","O","X","X"}
    };

    sol.convertZerosToX(grid);
    for(int i=0 ; i<grid.size() ; i++){
        for(int j=0 ; j<grid[i].size() ; j++){
            
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}