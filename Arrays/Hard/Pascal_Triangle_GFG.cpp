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

// working
class Solution{
public:
    long long modInverse(long long a, long long m) {
        long long m0 = m;
        long long y = 0, x = 1;
        if (m == 1)
            return 0;
        while (a > 1) {
            long long q = a / m;
            long long t = m;
            m = a % m, a = t;
            t = y;
            y = x - q * y;
            x = t;
        }
        if (x < 0)
            x += m0;
        return x;
    }
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        vector<ll>list;
        ll int mod=1e9+7;
        ll ans=1;
        list.push_back(ans);
        for(int col=1;col<n;col++)
        {
            ans=(ans*(n-col))%mod;
            ans=(ans*modInverse(col,mod))%mod;
            ans=ans%mod;
            list.push_back(ans);
        }
        return list;
    }
};