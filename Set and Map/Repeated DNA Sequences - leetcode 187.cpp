// Problem description @ https://leetcode.com/problems/repeated-dna-sequences/

// C++ : 14th Feb 2020
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> set1;
        set<string> set2;
        vector<string> v;
        if (s.length() < 11)
            return v;
        for (int i = 0; i < s.length() - 10 + 1; ++i)
        {
            string substr = s.substr(i, 10);
            if ( set1.emplace(substr).second == false)
                set2.emplace(substr);
        }
        for ( auto it = set2.cbegin(); it != set2.end(); ++it)
            v.emplace_back(*it);
        return v;
    }
};