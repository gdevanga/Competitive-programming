// Problem Description @ https://leetcode.com/problems/guess-number-higher-or-lower/description/
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0

// C++
int guess(int num);
class Solution {
public:
    int guessNumber(int n) {
        int low = 0;
        int high = n;
        while (high - low > 1)
        {
            int mid = low + (high - low)/2;
            int res = guess(mid);
            if (res == 0)
                return mid;
            else if (res == -1)
                high = mid;
            else
                low = mid;
        }
        return n;
    }
};


// JAVA - 4th Feb 2020
public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int low = 1;
        int high = n;
        while (low < high - 1)
        {
            int mid = low + (high - low) / 2;
            int result = guess(mid);
            if (result == 0)
                return mid;
            else if (result == -1)
                high = mid;
            else
                low = mid;
        }
        if (guess(low) == 0)
            return low;
        return high;
    }
}