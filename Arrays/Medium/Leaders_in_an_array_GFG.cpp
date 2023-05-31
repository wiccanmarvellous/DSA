#include <bits/stdc++.h>
using namespace std;

// Brute    TC O(n * n)     SC O(1)
class Solution
{
public:
    vector<int> leaders(int a[], int n)
    {
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int flag = 1;
            for (int j = i; j < n; j++)
            {
                if (a[i] < a[j])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                ans.push_back(a[i]);
        }
        return ans;
    }
};

// Optimal     TC O(n)      SC O(1)
class Solution
{
public:
    vector<int> leaders(int a[], int n)
    {
        vector<int> ans;
        int i = n - 1, rmax = a[n - 1];
        while (i >= 0)
        {
            if (a[i] >= rmax)
            {
                ans.push_back(a[i]);
                rmax = a[i];
            }
            i--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};