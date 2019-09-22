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