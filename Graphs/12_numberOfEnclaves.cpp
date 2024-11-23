#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int delRow[] = {-1, 0, 1, 0}; // Row movement directions
        int delCol[] = {0, 1, 0, -1}; // Column movement directions

        int n = grid.size(); // Number of rows
        int m = grid[0].size(); // Number of columns

        // Visited matrix to track processed cells
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        // Step 1: Mark all land cells connected to the boundary as visited
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the cell is on the boundary and is land
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && grid[i][j] == 1) {
                    vis[i][j] = 1;
                    q.push({i, j}); // Add it to the queue for BFS
                }
            }
        }

        // BFS to mark all cells connected to the boundary land cells
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Traverse all 4 possible directions
            for (int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                // If the neighbor cell is within bounds, not visited, and is land
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                    !vis[nRow][nCol] && grid[nRow][nCol] == 1) {
                    q.push({nRow, nCol});
                    vis[nRow][nCol] = 1;
                }
            }
        }

        // Step 2: Count land cells that are not visited (enclosed land)
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    int result = sol.numEnclaves(grid);
    cout << "Number of enclaves: " << result << endl;

    return 0;
}
