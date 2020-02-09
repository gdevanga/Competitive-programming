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

// Java - 4th Feb 2020
public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        
        while (low < high-1)
        {
            int mid = low + (high-low)/2;
            if (isBadVersion(mid) == true)
                high = mid;
            else
                low = mid;
        }
        if (isBadVersion(low) == true)
            return low;
        else
            return high;
        
    }
}