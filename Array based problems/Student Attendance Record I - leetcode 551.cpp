/*
Please check problem description @
https://leetcode.com/problems/student-attendance-record-i/description/
*/

class Solution {
public:
    bool checkRecord(string s) {
        const char* c = s.c_str();
        
        int aC = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (c[i] == 'A' )
            {
                ++aC;
                if (aC == 2)
                    return false;
            }
            else if (c[i] == 'L' )
            {
                if (i > 1 && c[i-1] == 'L' && c[i-2] == 'L')
                    return false;
            }
        }      
        
        return true;
    }
};