// Problem Description @ https://www.lintcode.com/problem/missing-string/description


class Solution {
public:
    /**
     * @param str1: a given string
     * @param str2: another given string
     * @return: An array of missing string
     */
    vector<string> missingString(string &str1, string &str2) {
        // Write your code here
        
                unordered_set<string> set1;
        istringstream ss1(str1);
        
        do { 
            string word; 
            ss1 >> word;
            
            set1.emplace(word);
        }while(ss1);
        
        istringstream ss2(str2);
        do { 
            string word; 
            ss2 >> word;
            
            //cout << " word " << word << " ";
            set1.erase(word);
            
        }while(ss2);
        
        vector<string> v;
        for (auto it = set1.cbegin(); it != set1.cend(); ++it)
        {
            //cout << *it << endl;
            v.emplace_back(*it);
        }
        
        return v;
    }
};