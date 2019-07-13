/*
*	find problem description @
*	https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        int i = 0;
        for (int j = 1; j < nums.size(); ++j)
        {
            if (nums[i] != nums[j])
            {
                nums[++i] = nums[j];
            }
        }
        return ++i;
    }
};