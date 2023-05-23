#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    int n = a.size(), len = 0;
    long long s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            s = 0;
            for (int k = i; k <= j; k++) {
              s += a[k];
            }
            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}