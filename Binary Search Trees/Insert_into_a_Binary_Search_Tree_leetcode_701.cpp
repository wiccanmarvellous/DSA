#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), righ(right){}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *newnode = new TreeNode(val);
        if (root == nullptr)
            return newnode;
        if (root->left == nullptr && root->right == nullptr) {
            if (val < root->val)
                root->left = newnode;
            else
                root->right = newnode;
        }
        else if (val < root->val) {
            if (root->left == nullptr)
                root->left = newnode;
            else
                insertIntoBST(root->left, val);
        }
        else if (val > root->val) {
            if (root->right == nullptr)
                root->right = newnode;
            else
                insertIntoBST(root->right, val);
        }
        return root;
    }
};