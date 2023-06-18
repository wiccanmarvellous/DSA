#include <bits/stdc++.h>
using namespace std;

// Brute        TC O(n * n * n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
            int sum = 0;
                for (int l = i; l <= j; l++) {
                    sum += nums[l];
                }
                if (sum == k)
                        count++;
            }
        }
        return count;
    }
};

// Better       TC O(n * n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), count = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == k)
                    count++;
            }
        }
        return count;
    }
};

// Optimal      TC O(n)     SC O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), count = 0, sum = 0;
        unordered_map<int, int> dict;
        dict[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (dict.find(sum - k) != dict.end())
                count += dict[sum - k];
            dict[sum]++;
        }
        return count;
    }
};