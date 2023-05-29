#include <bits/stdc++.h>
using namespace std;

// Brute
class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        next_permutation(arr.begin(), arr.end());
        return arr;
    }
};

// Optimal  TC O(N)    SC O(1)
class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int ind = -1;
        for (int i = N - 1; i > 0; i--)
        {
            if (arr[i - 1] < arr[i])
                {
                    ind = i - 1;
                    break;
                }
        }
        if (ind == -1)
            reverse(arr.begin(), arr.end());
        else
        {
            for (int i = N - 1; i > 0; i--)
            {
                if (arr[i] > arr[ind])
                {
                    swap(arr[i], arr[ind]);
                    reverse(arr.begin() + ind + 1, arr.end());
                    break;
                }
            }
        }
        return arr;
    }
};