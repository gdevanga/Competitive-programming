// Problem Description @ https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    int ary[26] = { 0 };
    bool checkAry()
    {
        for (int i : ary)
            if (i != 0)
                return false;
        return true;
    }
    
    void printAry()
    {
        for (int i = 0; i < 26; ++i)
        {
            cout << ary[i];
            if (i % 5 == 0)
                cout << " ";
        }
        cout << endl;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        
        int len = p.length();
        if (len > s.length())
            return v;
        
        const char* cp = p.c_str();
        for (int i = 0; i < p.length(); ++i)
        {
            ++ary[cp[i] - 'a'];
        }
        
        const char* cs = s.c_str();
        for (int i = 0; i < len; ++i)
        {
            --ary[cs[i] - 'a'];
        }
        printAry();
         if (checkAry())
              v.push_back(0);
           
        
        for (int i = len; i < s.length(); ++i) 
        {
            --ary[cs[i] - 'a'];
            ++ary[cs[i-len] - 'a'];
            
             if (checkAry())
              v.push_back(i-len+1);
            
        }
        return v;
    }
    
    
    bool isAnagram(string s, string t) {
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
    
    
    vector<int> findAnagrams2(string s, string p) {
        vector<int> v;
        
        int len = p.length();
        if (len > s.length())
            return v;
        
        for (int i = 0; i < s.length() - len + 1; ++i) 
        {
            string s2 = s.substr(i, len);
            if (isAnagram(p, s2))
              v.push_back(i);
        }
        return v;
    }
    
    
    vector<int> findAnagrams1(string s, string p) {
        vector<int> v;        
        
        int len = p.length();
        if (len > s.length())
            return v;
        
        sort (p.begin(), p.end());

        for (int i = 0; i < s.length() - len + 1; ++i)
        {
            string s2 = s.substr(i, len);
            sort (s2.begin(), s2.end());
            if (s2 == p)
                v.push_back(i);
        }
        return v;
    }
};