#include <bits/stdc++.h>
using namespace std;

// Brute        TC  O(n * m)        SC O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];
        for (int i = 0; i < strs.size(); i++) {
            int n = s.size() < strs[i].size() ? s.size() : strs[i].size();
            for (int j = 0; j < s.size(); j++) 
                if (s[j] != strs[i][j])
                    s = s.substr(0, j);
        }
        return s;
    }
};

// Optimal      TC O(n log n)       SC O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string minStr = strs[0], maxStr = strs[strs.size() - 1], ans = "";
        int n = min(minStr.size(), maxStr.size());
        for (int i = 0; i < n; i++) {
            if (minStr[i] != maxStr[i])
                break;
            ans += minStr[i];
        }
        return ans;
    }
};