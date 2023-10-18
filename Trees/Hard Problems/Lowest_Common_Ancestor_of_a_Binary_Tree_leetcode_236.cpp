#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Brute

class Solution {
public:

    bool helper(TreeNode* root, TreeNode* r, vector<TreeNode*> path, vector<TreeNode*> &finalPath) {
        if (root == NULL)
            return false;
        else if (root == r) {
            path.push_back(root);
            finalPath = path;
            return true;
        }

        else {
            path.push_back(root);
            if (helper(root->left, r, path, finalPath) || 
                helper(root->right, r, path, finalPath))
                return true;
        }
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        vector<TreeNode*> pathP, pathQ, temp;
        helper(root, p, temp, pathP);
        helper(root, q, temp, pathQ);
        for (auto i : pathP)
            cout << i->val;
        cout << endl;
        for (auto i : pathQ)
            cout << i->val;
        int minPathSize = min(pathP.size(), pathQ.size());
        for (int i = 0; i < minPathSize; i++) {
            if (pathP[i] != pathQ[i])
                break;
            ans = pathP[i];
        }
        return ans;
    }
};

// Optimal

class Solution {
public:
        
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;
        if (root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left && right)
            return root;
        else if (!left)
            return right;
        else
            return left;
        return NULL;
    }
};