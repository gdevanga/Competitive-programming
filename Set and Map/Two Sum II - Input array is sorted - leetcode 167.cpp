// Problem Description @ https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

// C++ : 14th Feb 2020
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
                v.push_back( m.find(target - nums[i])->second + 1 );
                v.push_back(i + 1);
                break;
            }
            m[nums[i]] = i;
        }
        return v;
    }


    vector<int> twoSum1(vector<int>& numbers, int target) {
        vector<int> v;
        if (numbers.size() < 2)
            return v;
        for (int i = 0; i < numbers.size() - 1; ++i)
        {
            for (int j = i + 1; j < numbers.size(); ++j)
            {
                int sum = numbers[i] + numbers[j];
                if (sum == target)
                {
                    v.push_back(i + 1);
                    v.push_back(j + 1);
                }
                else if (sum > target)
                {
                    break;
                }
            }
        }
        return v;
        
    }
};