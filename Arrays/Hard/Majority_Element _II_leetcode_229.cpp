#include <bits/stdc++.h>
using namespace std;

// Brute    TC O(n log n)       SC O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count = 1, n = nums.size();
        if (n == 1 || n == 2) {
            if (n == 2 && nums[0] == nums[1])
                nums.pop_back();
            return nums;
        }
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] != nums[i]) {
                if (count > n / 3 && (ans.size() == 0 || nums[i - 1] != ans.back()))
                    ans.push_back(nums[i - 1]);
                count = 1;
            }
            else
                count++;
        }
        if (count > n / 3 && (ans.size() == 0 || nums.back() != ans.back()))
            ans.push_back(nums.back());
        return ans;
    }
};

// Better       TC O(n)     SC O(n)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> dict;
        for (int i = 0; i < n; i++)
            dict[nums[i]]++;
        for (auto it : dict)
            if (it.second > n / 3)
                ans.push_back(it.first);
        return ans;
    }
};