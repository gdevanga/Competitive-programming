// Problem Description @ https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// Java - 5th Feb 2020
class Solution {
    public int findMin(int[] nums) {
        int low = 0;
        int high = nums.length-1;
        if (nums[low] < nums[high])
            return nums[low];
        
        while (low < high -1)
        {
            int mid = low + (high-low)/2;
            if (nums[mid-1] < nums[mid] && nums[mid+1] < nums[mid])
                return nums[mid+1];
            else if (nums[mid] > nums[low])
                low = mid;
            else
                high = mid;
        }
        if (nums[low] < nums[high])
            return nums[low];
        else
            return nums[high];
        
    }
}