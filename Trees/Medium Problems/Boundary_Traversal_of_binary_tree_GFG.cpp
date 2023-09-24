#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
public:
    void leftBoundTree(Node *root, vector<int> &ans) {
        if (root->left == NULL && root->right == NULL)
            return;
        else if  (root->left == NULL) {
            ans.push_back(root->data);
            leftBoundTree(root->right, ans);
        }
        else {
            ans.push_back(root->data);
            leftBoundTree(root->left, ans);
        }
    }
    
    void leafNodes(Node *root, vector<int> &ans) {
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }
        if (root->left) leafNodes(root->left, ans);
        if (root->right) leafNodes(root->right, ans);
    }
    
    void rightBoundTree(Node *root, vector<int> &temp) {
        if (root->right == NULL && root->left == NULL)
            return;
        else if (root->right == NULL) {
            temp.push_back(root->data);
            rightBoundTree(root->left, temp);
        }
        else {
            temp.push_back(root->data);
            rightBoundTree(root->right, temp);
        }
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> ans, temp;
        if (root == NULL)
            return ans;
        ans.push_back(root->data);
        
        if (root->left) leftBoundTree(root->left, ans);
        
        if (root->left || root->right) leafNodes(root, ans);
        
        if (root->right) rightBoundTree(root->right, temp);
        reverse(temp.begin(), temp.end());
        
        for (auto i : temp) ans.push_back(i);
        return ans;
    }
    
};