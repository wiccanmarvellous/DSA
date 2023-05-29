#include <bits/stdc++.h>
using namespace std;

// Brute
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

// Optimal  TC O(n) SC O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int>::iterator i = nums.end() - 1, j = nums.end() - 1;
        while (i != nums.begin())
        {
            if (*(i - 1) < *i)
            {
                while (j != nums.begin() && *j <= *(i - 1))
                    j--;
                swap(*(i - 1), *j);
                sort(i, nums.end());
                break;
            }
            i--;
        }
        if (i == nums.begin())
            reverse(nums.begin(), nums.end());
    }
};