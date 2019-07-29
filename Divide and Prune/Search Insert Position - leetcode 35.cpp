/*
*   problem description @
*   https://leetcode.com/problems/search-insert-position/
*/
class Solution {
public:
    int searchInsert(vector<int>& a, int target) {
        if (target <= a[0]) return 0;
        if (target > a[a.size()-1]) return a.size();

        int left = 0;
        int right = a.size()-1;

        while (right - left > 1 )
        {
            int mid = (left + right)/2;
            if (a[mid] == target)
                return mid;
            else if (target > a[mid])
                left = mid;
            else
                right = mid;
        }
        return right;
    }
};