#include <bits/stdc++.h>
using namespace std;


class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void inOrder(TreeNode *root, vector<int> &ino) {
    if (root == NULL)
        return;
    inOrder(root->left, ino);
    ino.push_back(root->data);
    inOrder(root->right, ino);
    return;
}
void preOrder(TreeNode *root, vector<int> &pre) {
    if (root == NULL)
        return;
    pre.push_back(root->data);
    preOrder(root->left, pre);
    preOrder(root->right, pre);
    return;
}
void postOrder(TreeNode *root, vector<int> &pos) {
    if (root == NULL)
        return;
    postOrder(root->left, pos);
    postOrder(root->right, pos);
    pos.push_back(root->data);
    return;
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>> ans;
    vector<int> ino, pre, pos;
    inOrder(root, ino);
    preOrder(root, pre);
    postOrder(root, pos);
    ans.push_back(ino);
    ans.push_back(pre);
    ans.push_back(pos);
    return ans;
}