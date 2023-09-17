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
    int heightDiff(TreeNode* root) {
        if (root == NULL)
            return 0;

        int l = heightDiff(root->left);
        int r = heightDiff(root->right);
        if (abs(l - r) > 1 || l == -1 || r == -1)
            return -1;
        return max(l, r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return heightDiff(root) == -1 ? false : true;
    }
};