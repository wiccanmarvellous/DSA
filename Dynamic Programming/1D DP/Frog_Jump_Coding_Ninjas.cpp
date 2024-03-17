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
