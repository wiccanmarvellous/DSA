#include <bits/stdc++.h>
using namespace std;

// Brute        TC O(n * n * n * n)     SC O(n * 4)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> tset;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {
                        long long sum = nums[i] + nums[j];
                        sum += nums[k];
                        sum += nums[l];
                        if (sum == target) {
                            vector<int> temp{nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            tset.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans(tset.begin(), tset.end());
        return ans;
    }
};

// Better       TC O(n * n * n)     SC O(n + n)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> tset;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                set<int> hashset;
                for (int k = j + 1; k < n; k++) {
                    int fourth = target - (nums[i] + nums[j] + nums[k]);
                    if (hashset.find(fourth) != hashset.end()) {
                        vector<int> temp{nums[i], nums[j], nums[k], fourth};
                        sort(temp.begin(), temp.end());
                        tset.insert(temp);
                    }
                    else
                        hashset.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(tset.begin(), tset.end());
        return ans;
    }
};