#include <bits/stdc++.h>
using namespace std;

// Brute O(n^3)
// int longestSubarrayWithSumK(vector<int> a, long long k) {
//     int n = a.size(), len = 0;
//     long long s = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = i; j < n; j++) {
//             s = 0;
//             for (int k = i; k <= j; k++) {
//               s += a[k];
//             }
//             if (s == k)
//                 len = max(len, j - i + 1);
//         }
//     }
//     return len;
// }

// Brute O(n^2)
// int longestSubarrayWithSumK(vector<int> a, long long k) {
//     int n = a.size(), s = 0, len = 0;
//     for (int i = 0; i < n; i++) {
//         s = 0;
//         for (int j = i; j < n; j++) {
//             s += a[j];
//             if (s == k) {
//                 len = max(len, j - i + 1);
//             }
//         }
//     }
//     return len;
// }

// Better TC O(n log n)  SC O(n)
// if negative value also included
// int longestSubarrayWithSumK(vector<int> a, long long k) {
//     map<long long, int> hash;
//     long long sum = 0;
//     int len = 0;
//     for (int i = 0; i < a.size(); i++) {
//         sum += a[i];
//         if (hash.find(sum - k) != hash.end() && len < (i - hash[sum - k]))
//             len = (i - hash[sum - k]);
//         if (hash.find(sum) == hash.end())
//             hash[sum] = i;
//     }
//     return len;
// }

// Best  TC O(2n)  SC O(1)
// if negative value not included, only zeros and positives
int longestSubarrayWithSumK(vector<int> a, long long k)
{
    int left = 0, right = 0, len = 0, n = a.size();
    long long sum = 0;
    while (right < n)
    {
        sum += a[right];
        while (left <= right && sum > k)
            sum -= a[left++];
        if (sum == k)
            len = max(len, right - left + 1);
        right++;
    }
    return len;
}
