// Problem Description @ https://leetcode.com/problems/find-peak-element/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int high = nums.size()-1;
        int low = 0;
        
        int mid;
        
        while (high - low > 1)
        {
            mid = low + (high-low)/2;
            
            //cout << "low:" << low << " mid : " << mid << " high : " << high << endl;
            
            int leftLow = nums[mid] > nums[mid-1];
            int rightLow = nums[mid] > nums[mid+1];
            if (leftLow && rightLow)
            {
                return mid;
            }
            if (leftLow)
                low = mid;
            else
                high = mid;
        }
        
        if (nums[high] > nums[low])
            return high;
        else
            return low;
    }
};


// Java 4th Feb 2020
class Solution {
    public int findPeakElement(int[] nums) {
        int low = 0;
        int high = nums.length-1;
        while (low < high-1)
        {
            int mid = low + (high-low)/2;
            if (nums[mid-1] < nums[mid] && nums[mid+1] < nums[mid])
                return mid;
            else if (nums[mid-1] <= nums[mid])
                low = mid;
            else
                high = mid;
        }
        if (nums[low] > nums[high])
            return low;
        else
            return high;
    }
}