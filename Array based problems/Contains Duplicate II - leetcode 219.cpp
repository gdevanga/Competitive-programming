/*
*	find problem description @
*	https://leetcode.com/problems/contains-duplicate-ii/description/
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k){
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (s.size() > k)
                s.erase(nums[i-k-1]);
            if (s.insert(nums[i]).second == false) return true;
        }
        return false;
    }
};