// Problem description @ https://leetcode.com/problems/valid-anagram/

 

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
  
        const char* cs = s.c_str();
        const char* ct = t.c_str();

        unordered_map<char, int> m;
        for (int i = 0; i < s.length(); ++i)
            ++m[cs[i] - 'a'];
        
        for (int i = 0; i < s.length(); ++i)
            --m[ct[i] - 'a'];
        
        for (auto it = m.cbegin(); it != m.end(); ++it)
            if (it->second != 0)
                return false;
        return true;

    }
    
    bool isAnagram2(string s, string t) {
        // sort and compare
        if (s.length() != t.length())
            return false;

        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        
        const char* cs = s.c_str();
        const char* ct = t.c_str();

        for (int i = 0; i < s.length(); ++i)
            if (cs[i] != ct[i])
                return false;
        return true;

    }
    bool isAnagram1(string s, string t) {
        int ary[26] = { 0 };
        if (s.length() != t.length())
            return false;
        
        const char* cs = s.c_str();
        for (int i = 0; i < s.length(); ++i)
        {
            ++ary[cs[i] - 'a'];
        }
        
        const char* ct = t.c_str();
        for (int i = 0; i < t.length(); ++i)
        {
            --ary[ct[i] - 'a'];
        }
        
        for (int a : ary)
            if (a != 0)
                return false;
        return true;
    }
};