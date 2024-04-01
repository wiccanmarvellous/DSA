#include <bits/stdc++.h>
using namespace std;

// Memoization TC O(n) SC O(n)
class Solution{
private:
    int helper(int *arr, int n, vector<int> &dp) {
        if (n == 0)
            return arr[n];
        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int pick = arr[n] + helper(arr, n - 2, dp);
        int notPick = 0 + helper(arr, n - 1, dp);
        return dp[n] = max(pick, notPick);
    }
public:	
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n, -1);
	    return helper(arr, n - 1, dp);
	}
};

// Tabulation   TC O(n) SC O(n)
class Solution{
public:	
	int findMaxSum(int *arr, int n) {
	   vector<int> dp(n, -1);
	   dp[0] = arr[0];
	   for (int i = 1; i < n; i++) {
	        int a = 0 + dp[i - 1];
	        int b = arr[i];
	        if (i > 1)
	            b += dp[i - 2];
	        dp[i] = max(a, b);
	   }
	   return dp[n - 1];
	}
};

// Tabulation TC O(n) SC O(1)
class Solution{
public:	
	int findMaxSum(int *arr, int n) {
	   int prev = arr[0], prev2 = 0;
	   for (int i = 1; i < n; i++) {
	        int a = 0 + prev;
	        int b = arr[i];
	        if (i > 1)
	            b += prev2;
	        prev2 = prev;
	        prev = max(a, b);
	   }
	   return prev;
	}
};