/*
*	find problem description @
*	https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3)
            return nums.size();
        int i = 0;
        int count = 1;
        for (int j = 1; j < nums.size(); ++j)
        {
            if (nums[i] != nums[j] )
            {
                nums[++i] = nums[j];
                count = 1;
            }
            else
            {
                if (count == 1)
                    nums[++i] = nums[j];
                ++count;
            }
        }
        return ++i;
    }
};