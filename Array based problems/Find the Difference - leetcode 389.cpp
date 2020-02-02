/*
* find problem description @
* https://leetcode.com/problems/find-the-difference/description/
*/
// C++
class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        const char* s1 = s.c_str();
        const char* s2 = t.c_str();
        
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i]-'a' != t[i]-'a')
                return t[i];
        }
        return t[t.length()-1];
    }
};

// Java solution - 1st Feb 2020
class Solution {
    public char findTheDifference(String s, String t) {
        char sAry[] = s.toCharArray();
        char tAry[] = t.toCharArray();
        Arrays.sort(sAry);
        Arrays.sort(tAry);
        for (int i = 0; i < s.length(); ++i)
        {
            if (sAry[i] != tAry[i])
                return tAry[i];
        }
        return tAry[s.length()];
    }
}