/*
*   find problem description @
*   https://leetcode.com/problems/triangle/
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int r = t.size();
        int c = t[t.size()-1].size();
        int mT[r][c];
        
        for (int j = 0; j < c; ++j)
            mT[r-1][j] = t[r-1][j];
        
        for (int i = t.size()-2; i >= 0; --i)
        {
            for (int j = 0; j < t[i].size(); ++j)
            {
                mT[i][j] = min(mT[i+1][j], mT[i+1][j+1]) + t[i][j];
            }
        }
        return mT[0][0];
    }
};