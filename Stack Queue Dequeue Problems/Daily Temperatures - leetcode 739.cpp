/*
Please find problem description @
https://leetcode.com/problems/daily-temperatures/
*/

class Solution {
    
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> diff(T.size());
        stack<int> s;

        for (int i = 0; i < T.size(); ++i)
        {
            while (s.empty() == false && T[s.top()] < T[i])
            {
                diff[s.top()] = i-s.top();  
                s.pop();
            }
            s.push(i);
        }
        return diff;
    }
};