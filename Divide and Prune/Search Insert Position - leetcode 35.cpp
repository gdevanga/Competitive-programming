/*
*   problem description @
*   https://leetcode.com/problems/search-insert-position/
*/
// C++
class Solution {
public:
    int searchInsert(vector<int>& a, int target) {
        if (target <= a[0]) return 0;
        if (target > a[a.size()-1]) return a.size();

        int left = 0;
        int right = a.size()-1;

        while (right - left > 1 )
        {
            int mid = (left + right)/2;
            if (a[mid] == target)
                return mid;
            else if (target > a[mid])
                left = mid;
            else
                right = mid;
        }
        return right;
    }
};

// Java - 4th Feb 2020
class Solution {
    public int searchInsert(int[] nums, int target) {
        int low = 0;
        int high = nums.length - 1;
        
        if (nums[high] < target)
            return high + 1;
        if (nums[low] >= target)
            return low;
        
        while (low < high -1)
        {
            int mid = low + (high - low) / 2;
            if (target == nums[mid])
                return mid;
            else if (target > nums[mid])
               low = mid; 
            else
                high = mid;
            System.out.println(" low " + low + " mid " + mid + " high " + high);
        }
        return high;
    }
}