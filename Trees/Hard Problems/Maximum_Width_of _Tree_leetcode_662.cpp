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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans = 0;
        if (root == NULL)   return ans;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            long long size = q.size();
            long long firstIdx = q.front().second;
            long long lastIdx = q.back().second;

            for (long long i = 0; i < size; i++) {
                TreeNode *node = q.front().first;
                long long idx = q.front().second - firstIdx;
                q.pop();

                if (node->left) q.push({node->left, idx * 2 + 1});
                if (node->right) q.push({node->right, idx * 2 + 2});
            }
            ans = max(ans, lastIdx - firstIdx + 1);
        }
        return ans;
    }
};