/*
*	find problem description @
*	https://leetcode.com/problems/remove-element/description/
*/
// C++
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

// Written in Java on 1st Feb 2020
class Solution {
    public boolean containsDuplicate(int[] nums) {
        Arrays.sort(nums);
        for (int i = 1; i < nums.length; ++i)
        {
            if (nums[i] == nums[i-1])
                return true;
        }
        return false;
    }
}