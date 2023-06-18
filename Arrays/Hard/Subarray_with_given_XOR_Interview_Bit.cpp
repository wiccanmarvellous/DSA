#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int> &A, int B){};
};

// Brute        TC O(n * n * n)
int Solution::solve(vector<int> &A, int B) {
    int count = 0;
    for (int i = 0; i < A.size(); i++) {
        for (int j = i; j < A.size(); j++) {
            int X = 0;
            for (int k = i; k <= j; k++) {
                X = X ^ A[k];
            }
            if (X == B)
                count++;
        }
    }
    return count;
}


// Better        TC O(n * n)
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

// Optimal      TC O(n)     SC O(n)
int Solution::solve(vector<int> &A, int B) {
    map<int, int> hash;
    hash[0] = 1;
    int X = 0, count = 0;
    for (int i = 0; i < A.size(); i++) {
        X = X ^ A[i];
        count += hash[X ^ B];
        hash[X]++;
    }
    return count;
}
