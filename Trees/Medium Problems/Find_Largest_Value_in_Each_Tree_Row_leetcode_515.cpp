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

//BFS
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (root == NULL)   return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            int maxRowVal = q.front()->val;
            while (n--) {
                TreeNode* node = q.front();
                int nodeVal = q.front()->val;
                q.pop();
                maxRowVal = max(maxRowVal, nodeVal);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(maxRowVal);
        }
        return ans;
    }
};

//DFS Pre Order
class Solution {
private:
    void helper(TreeNode* root, vector<int> &ans, int row) {
        if (root == NULL)
            return;

        if (row < ans.size())
            ans[row] = max(ans[row], root->val);
        else
            ans.push_back(root->val);

        helper(root->left, ans, row + 1);
        helper(root->right, ans, row + 1);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        helper(root, ans, 0);
        return ans;
    }
};

//DFS Post Order
class Solution {
private:
    void helper(TreeNode* root, vector<int> &ans, int row) {
        if (root == NULL)
            return;

        helper(root->left, ans, row + 1);
        helper(root->right, ans, row + 1);

        if (row > ans.size())
            ans.resize(row, INT_MIN);
        ans[row - 1] = max(ans[row - 1], root->val);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        helper(root, ans, 1);
        return ans;
    }
};