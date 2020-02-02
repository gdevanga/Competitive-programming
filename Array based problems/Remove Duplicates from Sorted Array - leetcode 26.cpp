/*
*	find problem description @
*	https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
*/

/* C++*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        int i = 0;
        for (int j = 1; j < nums.size(); ++j)
        {
            if (nums[i] != nums[j])
                nums[++i] = nums[j];
        }
        return i + 1;
    }
};

/*Java - Not optimzed */
class Solution {
    public int removeDuplicates(int[] nums) {
       int i = 0;
        for (int j = 0; j < nums.length;  ++j)
        {
            if (i == j)
                continue;
            while (j < nums.length && nums[i] == nums[j])
                ++j;
            if (j < nums.length)
                nums[++i] = nums[j];
        }
        return i + 1;
    }
}

/*Java - Optimized*/
class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length < 2) return nums.length;
        int i = 0;
        for (int j = 1; j < nums.length;  ++j)
        {
            if (nums[i] != nums[j])
                nums[++i] = nums[j];
        }
        return i + 1;
    }
}