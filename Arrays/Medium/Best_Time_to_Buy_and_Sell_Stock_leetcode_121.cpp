#include <bits/stdc++.h>
using namespace std;

// Brute    TC O(n*n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, n = prices.size();
        for (int i = 0; i < n; i++) {
            int pro = 0;
            for (int j = i; j < n; j++) {
                pro = prices[j] - prices[i];
                profit = max(profit, pro);
            }
        }
        if (profit < 0)
            profit = 0;
        return profit;
    }
};

// Optimal      TC O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), profit, maxProfit = 0, min = prices[0];
        for (int i = 0; i < n; i++) {
            profit = prices[i] - min;
            maxProfit = max(maxProfit, profit);
            if (profit < 0)
                min = prices[i];
        }
        if (maxProfit < 0)
            maxProfit = 0;
        return maxProfit;
    }
};

// Optimal      TC O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, maxProfit = 0, buy = prices[0], n = prices.size();
        for (int i = 0; i < n; i++) {
            profit = prices[i] - buy;
            maxProfit = max(maxProfit, profit);
            buy = min(buy, prices[i]);
        }
        return maxProfit;
    }
};