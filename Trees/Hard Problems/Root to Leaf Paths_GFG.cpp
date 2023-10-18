#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
};

/* The function should print all the paths from root
 to leaf nodes of the binary tree */
 
void helper(Node *root, vector<int> temp, vector<vector<int>> &ans) {
    if (root->left == NULL && root->right == NULL) {
        temp.push_back(root->data);
        ans.push_back(temp);
        temp.clear();
        return;
    }
    else if (root->left == NULL) {
        temp.push_back(root->data);
        helper(root->right, temp, ans);
    }
    else if (root->right == NULL) {
        temp.push_back(root->data);
        helper(root->left, temp, ans);
    }
    else {
        temp.push_back(root->data);
        helper(root->left, temp, ans);
        helper(root->right, temp, ans);
    }
}
 
vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>> ans;
    vector<int> temp;
    helper(root, temp, ans);
    return ans;
}