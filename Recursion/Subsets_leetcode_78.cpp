#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(vector<int> nums, vector<vector<int>> &ans, vector<int> partAns) {
        if (nums.size() == 0) {
            ans.push_back(partAns);
            return;
        }
        auto ele = nums.back();
        nums.pop_back();
        dfs(nums, ans, partAns);
        partAns.push_back(ele);
        dfs(nums, ans, partAns);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> partAns;
        dfs(nums, ans, partAns);
        return ans;
    }
};