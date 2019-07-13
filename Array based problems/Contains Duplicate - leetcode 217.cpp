/*
*	find problem description @
*	https://leetcode.com/problems/remove-element/description/
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums){
        if (nums.size() < 2)
            return false;
        std::sort(nums.begin(), nums.end());
        
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i-1] == nums[i])
                return true;
        }
        return false;
    }
};