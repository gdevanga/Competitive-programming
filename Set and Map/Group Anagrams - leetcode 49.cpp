// Problem Description @ https://leetcode.com/problems/group-anagrams/


// C++ : 12th feb 2020
class Solution {
public:
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
    
    vector<vector<string>> groupAnagrams1(vector<string>& strs) {
        vector<vector<string>> out2;
        for (int i = 0; i < strs.size(); )
        {
            vector<string> out1;
            for (int j = i+1; j < strs.size();)
            {
                if (isAnagram(strs[i], strs[j]))
                {
                    out1.push_back(strs[j]);
                    strs.erase(strs.begin()+j);
                }
                else
                {
                    ++j;
                }
            }
            out1.push_back(strs[i]);
            strs.erase(strs.begin()+i);
            out2.push_back(out1);
        }
        return out2;
    }
    
    // Solution 2 : Time : O((m * nlogn) + m)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        unordered_map<string, vector<string>>::iterator it;

        for (string s: strs)
        {
            string s2(s);
            sort(s2.begin(), s2.end());
            it = m.find(s2);
            if (it == m.end())
            {
                vector<string> v;
                v.emplace_back(s);
                m[s2] = v;
            }
            else
            {
                m[s2].emplace_back(s);
            }
        }
        
        vector<vector<string>> out1;
        for (auto it = m.cbegin(); it != m.cend(); ++it)
        {
            /*cout << it->first << " ";
            for (string s : it->second)
                cout << s << " ";
            cout << "\n";*/
            out1.emplace_back(it->second);
        }
        
        return out1;
    }

};