/*
Problem description @ https://leetcode.com/problems/continuous-subarray-sum/
*/

class Solution {

    bool isMultiple(int sum, int k)
    {
        if (k == 0)
        {
            if (sum == 0) return true;
            return false;
        }
        int div = sum/k;
        if (div * k == sum)
            return true;
        else
            return false;
    }
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        for (int i = 0 ; i < size; ++i)
        {
            int sum = nums[i];
            for (int j = i+1; j < size; ++j)
            {
                sum+=nums[j];
                
                if (isMultiple(sum, k))
                    return true;
            }
        }
        return false;
    }
};