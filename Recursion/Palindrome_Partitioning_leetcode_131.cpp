#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool checkPalindrome(string temp) {
        int i = 0, j = temp.size() - 1;
        while (i < j) {
            if (temp[i] != temp[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void dfs(string s, vector<vector<string>> &ans, vector<string> temp, int idx) {
        if (s.size() == idx) {
            ans.push_back(temp);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            string t = s.substr(idx, i - idx + 1);
            if (checkPalindrome(t)) {
                temp.push_back(t);
                dfs(s, ans, temp, i + 1);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        dfs(s, ans, temp, 0);
        return ans;
    }
};