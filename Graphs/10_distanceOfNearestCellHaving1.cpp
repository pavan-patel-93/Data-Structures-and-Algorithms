#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> dx = {-1, +0, +1, +0};
    vector<int> dy = {+0, +1, +0, -1};
    public:
    vector<vector<int>> distanceOfNearestCellHaving1(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> distance(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q;
        // <<x, y>, distance>
        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[0].size() ; j++){
                if(grid[i][j] == 1) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;

            int step = q.front().second;
            distance[row][col] = step;
            q.pop();
            for(int i=0 ; i<4 ; i++){
                int nRow = row + dx[i];
                int nCol = col + dy[i];

                if(
                    nRow >= 0 && nRow < n &&
                    nCol >= 0 && nCol < m &&
                    !visited[nRow][nCol] 
                ) {
                    q.push({{nRow, nCol}, step + 1});
                    visited[nRow][nCol] = 1;
                }
            }
        }
        return distance;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {
        {0, 0, 0}, 
        {0, 1, 0},
        {1, 0, 1}
    };

    vector<vector<int>> ans = sol.distanceOfNearestCellHaving1(grid);
    for(int i=0 ; i<ans.size() ; i++){
        for(int j=0 ; j<ans[i].size() ; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}