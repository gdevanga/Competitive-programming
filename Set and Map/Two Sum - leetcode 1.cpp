// Problem description @ https://leetcode.com/problems/two-sum/

// C++ 14th Feb 2020
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        unordered_map<int, int> m;
        if (nums.size() < 2)
            return v;
        m[nums[0]] = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (m.find(target - nums[i]) != m.end())
            {
                v.push_back( m.find(target - nums[i])->second );
                v.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }
        return v;
    }
};