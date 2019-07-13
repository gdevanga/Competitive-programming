/*
*	find the problem description @
*	https://leetcode.com/problems/find-the-duplicate-number/description/
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        bitset<30000> b;
        for (int i : nums)
        {
            if (b[i] == true)
                return i;
            else
                b.set(i);
        }
        return 0;
    }
};