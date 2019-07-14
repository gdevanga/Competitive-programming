/*
*   please find problem description @
*   https://leetcode.com/problems/min-cost-climbing-stairs/
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int mc[cost.size()+2] = {0};
        for (int i = cost.size()-1; i >= 0; --i)
        {
            mc[i] = min(cost[i]+mc[i+1], cost[i]+mc[i+2]);
        }
        // i can start on 0th index or 1st index.
        return min(mc[0],mc[1]);
    }
};