/*
find problem description @
https://leetcode.com/problems/set-mismatch/description/
*/
// C++
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums){
        sort(nums.begin(), nums.end());
        int rep = -1, missing = -1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (rep == -1 && nums[i] == nums[i-1])
                rep = nums[i];
            if (missing == -1 && nums[i] == nums[i-1]+2)
                missing = nums[i]-1;
        }
        if (missing == -1)
        {
            if (nums[nums.size()-1] == nums.size()-1)
                missing = nums.size();
            else
                missing = 1;
        }
        vector<int> v{rep,missing};
        return v;
    }
};


// Java - 1st Feb 2020
class Solution {
    public int[] findErrorNums(int[] nums) {
        int out[] = {0,0};
        Arrays.sort(nums);
        for (int i = 1; i < nums.length; ++i)
        {
            if (nums[i] == nums[i-1])
               out[0] = nums[i]; 
            if (nums[i] == nums[i-1] + 2)
                out[1] = nums[i-1] + 1;
        }
        if (out[1] == 0)
        {
            if (nums[nums.length - 1] == nums.length)
                out[1] = 1;
            else
                out[1] = nums.length;
        }
        return out;
    }

    public int[] findErrorNums1(int[] nums) {
        int out[] = {0,0};
        int aux[] = new int[nums.length + 1];
        for (int i = 0; i < nums.length; ++i)
        {
            ++aux[nums[i]];
        }
        
        for (int i = 0; i < aux.length; ++i)
        {
            if (aux[i] == 0)
                out[1] = i;
            if (aux[i] == 2)
                out[0] = i;
        }
        return out;
    }
}