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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode*> queue;
        queue.push(root);
        int flag = 0;
        while (!queue.empty()) {
            int size = queue.size();
            vector<int> subAns;
            TreeNode *temp = NULL;
            for (int i = 0; i < size; i++) {
                temp = queue.front();
                queue.pop();
                subAns.push_back(temp->val);
                if (temp->left != NULL) queue.push(temp->left);
                if (temp->right != NULL) queue.push(temp->right);
            }
            if (flag) {
                reverse(subAns.begin(), subAns.end());
                flag = 0;
            }
            else
                flag = 1;
            ans.push_back(subAns);
        }
        return ans;
    }
};