/*
find problem description @
https://leetcode.com/problems/set-mismatch/description/
*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums){
        sort(nums.begin(), nums.end());
        int rep = -1, missing = -1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (rep == -1 && nums[i] == nums[i-1])
                rep = nums[i];
            if (missing == -1 && nums[i] == nums[i-1]+2)
                missing = nums[i]-1;
        }
        if (missing == -1)
        {
            if (nums[nums.size()-1] == nums.size()-1)
                missing = nums.size();
            else
                missing = 1;
        }
        vector<int> v{rep,missing};
        return v;
    }
};