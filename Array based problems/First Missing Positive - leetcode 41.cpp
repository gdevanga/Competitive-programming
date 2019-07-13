/*
*	find problem description @
*	https://leetcode.com/problems/first-missing-positive/description/
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int min = 1;
        for (int i : nums)
        {
            if (i > 0 && i == min)
                ++min;
        }
        return min;
    }
};