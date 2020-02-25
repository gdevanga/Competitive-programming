// Problem description @ https://leetcode.com/problems/isomorphic-strings/


// c++ : 10th Feb 2020
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        const char* s1 = s.c_str();
        const char* t1 = t.c_str();
        
        map<char, char> m1;
        map<char, char> m2;
        for (int i = 0; i < s.length(); ++i)
        {
            if (m1.count(s1[i]) == 1 || m2.count(t1[i]) == 1)
            {
                if (m1[s1[i]] != t1[i] || m2[t1[i]] != s1[i])
                    return false;
            }
            else
            {
                m1.insert( std::pair<char, char>(s1[i], t1[i]));
                m2.insert( std::pair<char, char>(t1[i], s1[i]));
            }
        }
        return true;
    }
};

// c++
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        const char* p = s.c_str();
        const char* q = t.c_str();
        
        int len = s.length();
        unordered_map<char, char> m;
        unordered_set<char> se;
        for (int i = 0; i < len; ++i)
        {
            if (m.count(p[i]) == 0)
            {
                if (se.count(q[i]) == 1)
                    return false;
                m[p[i]] = q[i];
                se.emplace(q[i]);
                
            }
            else
            {
                //cout << "\n i " << i << " " << q[i] << "   " << m[p[i]];
                if (q[i] != m[p[i]])
                    return false;
            }
        }
        return true;
    }
};