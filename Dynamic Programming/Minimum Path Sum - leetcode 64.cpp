/*
*   please find problem description @
*   https://leetcode.com/problems/minimum-path-sum/
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    int r = grid.size()+1;
    int c = grid[0].size()+1;
    int mps[r][c] = {{0},{0}};
        
    for (int j = 0; j < c-1; ++j)
        mps[r-1][j] = INT_MAX;
    for (int i = 0; i < r-1; ++i)
        mps[i][c-1] = INT_MAX;
    
    mps[r-2][c-1] = mps[r-1][c-2] = 0;
    
    for (int j = c-2; j >= 0; --j)
        for (int i = r-2; i >= 0; --i)
            mps[i][j] = min(mps[i+1][j], mps[i][j+1]) + grid[i][j];
        
    return mps[0][0];
    }
};