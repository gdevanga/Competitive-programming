// Problem Description @ https://leetcode.com/problems/keyboard-row/


// C++ using set
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> out;
        for (string s : words)
        {
            if (wordCheck(s))
                out.emplace_back(s);
        }
        return out;
    }
    
    bool wordCheck(string& s)
    {
        set<char> s1 = {'Q', 'q', 'W', 'w', 'E', 'e', 'R', 'r', 'T', 't', 'Y', 'y', 'U', 'u', 'I', 'i', 'O', 'o', 'P', 'p' };
        set<char> s2 = {'A', 'a', 'S', 's', 'D', 'd', 'F', 'f', 'G', 'g', 'H', 'h', 'J', 'j', 'K', 'k', 'L', 'l' };
        set<char> s3 = {'Z', 'z', 'X', 'x', 'C', 'c', 'V', 'v', 'B', 'b', 'N', 'n', 'M', 'm'};
        
        const char* cStr = s.c_str();
        if (s1.count(cStr[0]) == 1)
            return letterCheck(s, s1);
        if (s2.count(cStr[0]) == 1)
            return letterCheck(s, s2);
        if (s3.count(cStr[0]) == 1)
            return letterCheck(s, s3);
        
        return true;
    }

    bool letterCheck(string& s, set<char>& st)
    {
        const char* cStr = s.c_str();
        for (int i = 0; i < s.length(); ++i)
        {
            if (0 == st.count(cStr[i]))
                return false;
        }
        return true;
    }
};

// C++ using map : 10th Feb 2020
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        std::map<char, int> m = { {'q',1}, {'w',1}, {'e',1}, {'r',1}, {'t',1}, {'y',1},{'u',1},{'i',1},{'o',1},{'p',1},
        {'a',2}, {'s',2}, {'d',2}, {'f',2}, {'g',2}, {'h',2}, {'j',2}, {'k',2}, {'l',2},
        {'z',3}, {'x',3}, {'c',3}, {'v',3}, {'b',3}, {'n',3}, {'m',3}};
        
        vector<string> out;
        for (string s: words)
        {
            char* cstr = s.c_str();
            int prev = m[tolower(cstr[0])];
            bool add = true;
            for (int i = 1; i < s.length(); ++i)
            {
                if (prev != m[ tolower(cstr[i]) ])
                {
                    add = false;
                    break;
                }
            }
            if (add)
                out.push_back(s);
        }
        return out;
    }
};