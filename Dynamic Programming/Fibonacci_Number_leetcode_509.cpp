#include <bits/stdc++.h>
using namespace std;

//Memoization
class Solution {
private:
    int dpFib(int n, vector<int> &dp) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        if (dp[n] != -1) return dp[n];
        dp[n] = dpFib(n - 1, dp) + dpFib(n - 2, dp);
        return dp[n];
    }
public:
    int fib(int n) {
        vector<int> dp(n + 1, -1);
        return dpFib(n, dp); 
    }
};

//Tabulation TC O(n) SC O(1)
class Solution {
public:
    int fib(int n) {
        if (n == 0)
            return 0;
        int prev = 1, preprev = 0;
        for (int i = 2; i <= n; i++) {
            int curr = prev + preprev;
            preprev = prev;
            prev = curr;
        }
        return prev;
    }
};