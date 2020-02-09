/*
Please check problem description @
https://leetcode.com/problems/student-attendance-record-i/description/
*/

// C++
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

//  JAVA solution 2nd Feb 2020
class Solution {
    public boolean checkRecord(String s) {
        char[] sAry = s.toCharArray();
        boolean absent = false;
        boolean late1 = false;
        boolean late2 = false;
        for (int i = 0; i < s.length(); ++i)
        {
            if (sAry[i] == 'A')
            {
                if (absent)
                    return false;
                absent = true;
                late1 = late2 = false;
            }
            if (sAry[i] == 'L')
            {
                if (late1 && late2)
                    return false;
                if (late1)
                    late2 = true;
                else
                    late1 = true;
            }
            else
            {
                late1 = late2 = false;
            }
        }
        return true;   
    }
}