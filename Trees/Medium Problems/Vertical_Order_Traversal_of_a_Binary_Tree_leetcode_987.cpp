#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<pair<int, int>, vector<int>> Map;
        map<int, vector<int>> nextMap;
        queue<pair<pair<int, int>, TreeNode*>> q;
        q.push({{0, 0}, root});
        while (!q.empty()) {
            TreeNode *node = q.front().second;
            int row = q.front().first.first;
            int col = q.front().first.second;
            q.pop();
            Map[{col, row}].push_back(node->val);
            if (node->left) q.push({{row + 1, col - 1}, node->left});
            if (node->right) q.push({{row + 1, col + 1}, node->right});
        }
        for (auto& i : Map)
            sort(i.second.begin(), i.second.end());
        for (auto i : Map)
            for (auto j : i.second)
                nextMap[i.first.first].push_back(j);
        for (auto i : nextMap)
            ans.push_back(i.second);
        return ans;
    }
};