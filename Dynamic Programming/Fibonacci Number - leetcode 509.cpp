/*
* find problem description @
* https://leetcode.com/problems/fibonacci-number/submissions/
*/
class Solution {
public:
    int fib(int N){
        if (N == 0) return 0;
        if (N == 1) return 1;
        int f1 = 0;
        int f2 = 1;
        int f;
        for (int i = 1; i < N; ++i)
        {
            f = f1 + f2;
            f1 = f2;
            f2 = f;
        }
        return f;
    }
    
    // Time and Space constraints!
    int fib1(int N) {
        if (N == 0)
            return 0;
        if (N == 1)
            return 1;
        return fib(N-1) + fib(N-2);
    }
};