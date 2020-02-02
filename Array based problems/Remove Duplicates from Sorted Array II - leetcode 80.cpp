/*
*	find problem description @
*	https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
*/
// C++ 
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

// Written in Java on 1st feb 2020
class Solution {
    public int removeDuplicates(int[] nums) {
        int count = 1;
        int j = 0;
        for (int i = 1; i < nums.length; ++i)
        {
            if (nums[i] == nums[i-1])
            {
                ++count;
                if (count < 3)
                {
                    ++j;
                    nums[j] = nums[i];
                }
            }
            else
            {
                count = 1;
                ++j;
                nums[j] = nums[i];
            }
        }
        return j + 1;
    
    }

