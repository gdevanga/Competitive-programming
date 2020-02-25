// Problem Description @ https://leetcode.com/problems/intersection-of-two-arrays/


// C++ : 11 Feb 2020
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        for (int i : nums1)
        {
            s1.emplace(i);
        }
        
        unordered_set<int> s2;
        for (int i : nums2)
        {
            if (s1.find(i) != s1.end())
            {
                s2.emplace(i);
            }
        }
        
        vector<int> out;
        for ( auto it = s2.cbegin(); it != s2.cend(); ++it )
            out.emplace_back(*it);
        
        return out;
    }
};