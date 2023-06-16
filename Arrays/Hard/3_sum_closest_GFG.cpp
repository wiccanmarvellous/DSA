#include <bits/stdc++.h>
using namespace std;

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