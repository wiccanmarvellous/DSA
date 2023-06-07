#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Better       TC O(n * n)     SC O(n)
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        if (n == 1)
            return {1};
        if (n == 2)
            return {1, 1};
        vector<ll> prev{1, 1}, curr;
        for (ll i = 2; i < n; i++) {
            curr.push_back(1);
            for (ll j = 0; j < prev.size() - 1; j++)
                curr.push_back(prev[j] + prev[j + 1]);
            curr.push_back(1);
            prev = curr;
            curr.clear();
        }
        return prev;
    }
};

// Better       TC O(n)     SC O(n)
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        ll t = 1;
        vector<ll> ans{1};
        for (ll i = 1; i < n; i++) {
            t = t * (n - i);
            t = t / (i);
            ans.push_back(t);
        }
        return ans;
    }
};