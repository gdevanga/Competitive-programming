/*
*	find the problem description @
*	https://leetcode.com/problems/find-the-duplicate-number/description/
*/
// C++
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


// JAVA 1st Feb 2020
class Solution {
    public int findDuplicate(int[] num) {
        int slow = num[0];
        int fast = num[num[0]];
        while (fast != slow)
        {
            slow = num[slow];
            fast = num[num[fast]];
        }
                
        // Find entry point of circle 
        fast = 0;
        while (slow != fast)
        {
            slow = num[slow];
            fast = num[fast];
        }
        
        return slow;
    }
}