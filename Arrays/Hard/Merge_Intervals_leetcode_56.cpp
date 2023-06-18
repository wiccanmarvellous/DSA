#include <bits/stdc++.h>
using namespace std;

// Optimal      TC O(n)     SC O(1)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        pair<int, int> range{intervals[0][0], intervals[0][1]};
        int n = intervals.size();
        for (int i = 0; i < n - 1; i++) {
            if (range.second >= intervals[i][0]) {
                if (range.second < intervals[i][1])
                    range.second = intervals[i][1];
                if (range.second < intervals[i + 1][0]) {
                    ans.push_back({range.first, range.second});
                    range = {intervals[i + 1][0], intervals[i + 1][0]};
                }
            }
        }
        if (range.second < intervals[n - 1][1])
            range.second = intervals[n - 1][1];
        ans.push_back({range.first, range.second});
        return ans;
    }
};