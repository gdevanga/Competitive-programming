// Problem Description @ https://leetcode.com/problems/unique-morse-code-words/


class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> v = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
            
        unordered_set<string> se;   
        for (string s : words)
        {
            const char* cstr = s.c_str();
            string out;
            for (int i = 0; i < s.length(); ++i)
            {
                out += v[cstr[i]-'a'];
            }
            se.emplace(out);
        }
        return se.size();
    }
};