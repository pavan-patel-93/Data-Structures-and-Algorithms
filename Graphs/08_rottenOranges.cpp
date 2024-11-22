#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> dx = {-1, 0, 1, 0}; 
    vector<int> dy = {0, 1, 0, -1}; 

public:
    int rottenOranges(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q; 
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }

        int time = 0;
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time, t);

            for (int i = 0; i < 4; i++) {
                int nRow = row + dx[i];
                int nCol = col + dy[i];

                if (
                    nRow >= 0 && nRow < n && 
                    nCol >= 0 && nCol < m && 
                    grid[nRow][nCol] == 1
                ) {
                    q.push({{nRow, nCol}, t + 1});
                    grid[nRow][nCol] = 2;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1; 
                }
            }
        }

        return time;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {2, 1, 1}, 
        {1, 1, 0},
        {0, 1, 1}
    };

    int ans = sol.rottenOranges(grid);
    if (ans == -1) {
        cout << "Not all oranges can be rotten." << endl;
    } else {
        cout << "Time required to rot all the oranges in the grid is: " << ans << " minutes." << endl;
    }
}
