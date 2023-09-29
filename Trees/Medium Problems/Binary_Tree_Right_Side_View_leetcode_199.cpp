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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        queue<pair<int, TreeNode*>> q;
        map<int, int> dict;
        q.push({0, root});
        while (!q.empty()) {
            TreeNode *node = q.front().second;
            int row = q.front().first;
            q.pop();
            dict[row] = node->val;
            if (node->left) q.push({row + 1, node->left});
            if (node->right) q.push({row + 1, node->right});
        }
        for (auto i : dict)
            ans.push_back(i.second);
        return ans;
    }
};