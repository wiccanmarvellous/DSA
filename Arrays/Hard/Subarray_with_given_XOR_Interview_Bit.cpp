#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int> &A, int B){};
};

// Brute        TC O(n * n)
int Solution::solve(vector<int> &A, int B) {
    int X = 0, count = 0;
    for (int i = 0; i < A.size(); i++) {
        for(int j = i; j < A.size(); j++) {
            X = X ^ A[j];
            if (X == B)
                count++;
        }
        X = 0;
    }
    return count;
}


