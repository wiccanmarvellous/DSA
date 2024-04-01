#include <bits/stdc++.h>
using namespace std;

// Memoization TC O(n) SC O(n)
class Solution {
private:
    int helper(vector<int> nums, vector<int> &dp, int n) {
        if (n == 0)
            return nums[n];
        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int rob = nums[n];
        if (n > 1)
            rob += helper(nums, dp, n - 2);
        int notRob = helper(nums, dp, n - 1);
        return dp[n] = max(rob, notRob);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(nums, dp, n - 1);
    }
};

// Tabulation   TC O(n) SC O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            int rob = nums[i];
            if (i > 1)
                rob += dp[i - 2];
            int notRob = dp[i - 1];
            dp[i] = max(rob, notRob);
        }
        return dp[n - 1];
    }
};

// Tabulation   TC O(n) SC O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev1 = nums[0], prev2 = 0;
        for (int i = 1; i < n; i++) {
            int rob = nums[i];
            if (i > 1)
                rob += prev2;
            int notRob = prev1;
            prev2 = prev1;
            prev1 = max(rob, notRob);
        }
        return prev1;
    }
};