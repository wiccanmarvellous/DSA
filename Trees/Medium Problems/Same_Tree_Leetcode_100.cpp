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
    int helper(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)
            return 0;
        else if (p == NULL || q == NULL || p->val != q->val)
            return -1;
        int l = helper(p->left, q->left);
        int r = helper(p->right, q->right);
        if (l == -1 || r == -1)
            return -1;
        return max(l, r) + 1;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return helper(p, q) == -1 ? false : true;
    }
};