#include <bits/stdc++.h>
using namespace std;

// Brute        TC O(n * n * n)
class Solution{
    public:
    int closest3Sum(int A[], int N, int X)
    {
        int min = INT_MAX, ans = -1;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                for (int k = j + 1; k < N; k++) {
                    int sum = A[i] + A[j] + A[k];
                    if (abs(sum - X) < min) {
                        min = abs(sum - X);
                        ans = sum;
                    }
                }
            }
        }
        return ans;
    }
};

// Optimal      TC O(n * n)
class Solution{
    public:
    int closest3Sum(int A[], int N, int X)
    {
        int min = INT_MAX, ans = 0;
        sort(A, A + N);
        for (int i = 0; i < N; i++) {
            if (i > 0 && A[i] == A[i - 1]) continue;
            int j = i + 1;
            int k = N - 1;
            while (j < k) {
                int sum = A[i] + A[j] + A[k];
                if (sum == X) {
                    return X;
                }
                else if (sum < X) {
                    int diff = X  - sum;
                    if (diff < min) {
                        min = diff;
                        ans = sum;
                    }
                    j++;
                }
                else {
                    int diff = sum - X;
                    if (diff < min) {
                        min = diff;
                        ans = sum;
                    }
                    k--;
                }
            }
        }
        return ans;
    }
};