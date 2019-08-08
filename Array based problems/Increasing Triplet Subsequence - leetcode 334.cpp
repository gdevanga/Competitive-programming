/*
Please check problem description @
https://leetcode.com/problems/increasing-triplet-subsequence/description/
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& v){
        if (v.size() < 3)
           return false;
        
        int n1 = INT_MAX, n2 = INT_MAX, n3 = INT_MAX;
        
        for (int e: v)
        {
            if (e <= n1)
            {
                n1 = e;
            }
            else if (e <= n2)
            {
                
                n2 = e;
            }
            else if (e <= n3)
            {
                n3 = e;
                return true;
            }
        }
        return false;
    }
};