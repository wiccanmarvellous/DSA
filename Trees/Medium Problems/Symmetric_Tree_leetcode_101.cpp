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
    bool helper(TreeNode* r1, TreeNode* r2) {
        if (r1 == NULL && r2 == NULL)
            return true;
        if ((r1 == NULL || r2 == NULL) || r1->val != r2->val)
            return false;
        bool l = helper(r1->left, r2->right);
        bool r = helper(r1->right, r2->left);
        return l && r;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return helper(root->left, root->right);
    }
};