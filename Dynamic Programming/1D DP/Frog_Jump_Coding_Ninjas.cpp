#include <bits/stdc++.h>
using namespace std;

//Memoization
#include <bits/stdc++.h> 
int helper(int n, vector<int> &heights, vector<int> &dp) {
    if (n == 0)
        return 0;

    if (dp[n] != -1)    return dp[n];

    int left = helper(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);
    
    int right = INT_MAX;
    if (n > 1)    right = helper(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);
    return dp[n] = min(left, right);
} 
int frogJump(int n, vector<int> &heights)
{
   vector<int> dp(n + 1, -1);
   return helper (n - 1, heights, dp);
}

//Tabulation
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, 0);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        int one = dp[i - 1] + abs(heights[i] - heights[i - 1]);

        int two = INT_MAX;
        if (i > 1) two = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        dp[i] = min(one, two);
    }
    return dp[n - 1];
}