#include <bits/stdc++.h>
using namespace std;

// Brute        TC O(n * n * n)     SC O(n * 3)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> tans;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (i != j && j != k && k != i && (nums[i] + nums[j] + nums[k] == 0)) {
                        vector<int> temp({nums[i], nums[j], nums[k]});
                        sort(temp.begin(), temp.end());
                        tans.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(begin(tans), end(tans));
        return ans;
    }
};