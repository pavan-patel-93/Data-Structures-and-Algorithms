#include<bits/stdc++.h>
using namespace std;

class Solution {
    int initialColor = 0;
    vector<int> dx = {-1, +0, +1, +0};
    vector<int> dy = {+0, +1, +0, -1};
    private:
        void dfs(int sr, int sc, vector<vector<int>>& filledImage, vector<vector<int>>& image, int newColor){
            filledImage[sr][sc] = newColor;
            int n = image.size();
            int m = image[0].size();

            for(int idx = 0 ; idx < 4 ; idx++){
                int nRow = sr + dx[idx];
                int nCol = sc + dy[idx];

                if( 
                    nRow < n && nRow >= 0 &&
                    nCol < m && nCol >= 0 &&
                    filledImage[nRow][nCol] != newColor &&
                    image[nRow][nCol] == initialColor
                ){
                    dfs(nRow, nCol, filledImage, image, newColor);
                }
            }

        }
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
            initialColor = image[sr][sc];
            vector<vector<int>> filledImage = image;
            dfs(sr, sc, filledImage, image, newColor);
            return filledImage;
        }
};

int main(){
    Solution sol;
    vector<vector<int>> image = {
        {1, 1, 1}, 
        {2, 2, 0},
        {2, 2, 2}
    };

    int sr = 2, sc = 0, newColor = 3;
    vector<vector<int>> ans = sol.floodFill(image, sr, sc, newColor);
    for(int i=0 ; i<ans.size() ; i++){
        for(int j=0 ; j<ans[i].size() ; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}