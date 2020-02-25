// Problem description @ https://leetcode.com/problems/first-unique-character-in-a-string/

// C++ 13th Feb 2020
class Solution {
public:
    int firstUniqChar(string s) {
        const char* cs = s.c_str();
        int ary[26] = { 0 };
        for (int i = 0; i < s.length(); ++i)
        {
            ++ary[cs[i] - 'a'];
        }
        
        for (int i = 0; i < s.length(); ++i)
        {
            if (ary[cs[i] - 'a'] == 1) 
                return i;
        }
        return -1;
        
    }
};