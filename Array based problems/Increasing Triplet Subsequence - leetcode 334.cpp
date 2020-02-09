/*
Please check problem description @
https://leetcode.com/problems/increasing-triplet-subsequence/description/
*/

// C++
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

// JAVA - 2nd Feb 2020
class Solution {
    public boolean increasingTriplet(int[] nums) {
        int n1 = Integer.MAX_VALUE - 1;
        int n2 = Integer.MAX_VALUE;
        for (int i : nums)
        {
            if (i > n2)
                return true;
            else if (i > n1)
                n2 = i;
            else if (i < n1)
                n1 = i;
        }
        return false;
    }
}