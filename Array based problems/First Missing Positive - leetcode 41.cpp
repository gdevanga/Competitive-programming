/*
*	find problem description @
*	https://leetcode.com/problems/first-missing-positive/description/
*/
// C++
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


// Java - 1st feb 2020
class Solution {
    public int firstMissingPositive(int[] nums) {
        Arrays.sort(nums); // O(nlogn)
        int min = 1;
        for (int i : nums)
        {
            if (i > 0 && i == min)
                ++min;
        }
        return min;
    }
}