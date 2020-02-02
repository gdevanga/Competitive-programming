/*
*	find problem description @
*	https://leetcode.com/problems/remove-element/description/
*/
// C++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = -1;
        for (int j = 0; j < nums.size(); ++j)
        {
            if (nums[j] != val)
            {
                nums[++i] = nums[j];
            }
        }
     return ++i;   
    }
};


// Written in Java on 1st Feb 2020
class Solution {
    public int removeElement(int[] nums, int val) {
    int j = 0;
        for (int i = 0; i < nums.length; ++i)
        {
            if (nums[i] != val)
            {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
}