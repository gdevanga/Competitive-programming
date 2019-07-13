/*
* find problem description @
* https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
*/
class Solution {
public:
    vector<int> findDisappearedNumbers1(vector<int>& nums) {
        vector<int> v;
        bitset<90000> b;
        b.set(0);
        for (int i : nums)
            b.set(i);
        
        for (int i = 0; i < nums.size()+1; ++i)
            if (b[i] == false)
                v.push_back(i);
        
        return v;
    }
    
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(), nums.end());
        
        if (nums.size() < 1)
            return v;
        // boundary conditions
        int c = 1;
        while ( c < *(nums.begin()))
        {
            v.push_back(c++);
        }
        
        int size = nums.size();
        for (int i = 1; i < size; ++i)
        {
            if (nums[i-1] != nums[i] && nums[i-1] +1 != nums[i])
            {
                for (int c = nums[i-1]+1; c < nums[i]; ++c)
                    v.push_back(c);
            }
        }
        
        // boundary conditions
        c = nums[size-1];
        while ( c < size)
        {
            v.push_back(++c);
        }
        return v;
    }
};