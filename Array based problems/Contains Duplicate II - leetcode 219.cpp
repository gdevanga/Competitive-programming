/*
*	find problem description @
*	https://leetcode.com/problems/contains-duplicate-ii/description/
*/
// C++
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


// Written in JAVA on 1st Feb 2020
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        for (int i = 0; i < nums.length; ++i)
        {
            for (int j = 0; j < k && i+j+1 < nums.length; j++)
                if (nums[i] == nums[i + j + 1])
                    return true;
        }
        return false;
    }
}