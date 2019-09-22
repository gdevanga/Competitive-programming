// Problem description @ https://leetcode.com/problems/first-bad-version/
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 0;
        int high = n;
        int mid;
        while (high - low > 1)
        {
            mid = low + (high - low)/2;
            if (isBadVersion(mid))
                high = mid;
            else
                low = mid;
            
        }
        if (!isBadVersion[low])
            return low;
        if (!isBadVersion[mid])
            return mid;
        return high;
        
    }
};