#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void getLeftBoundary(TreeNode<int> *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    else if (root->left == NULL)
    {
        ans.push_back(root->data);
        getLeftBoundary(root->right, ans);
    }
    else
    {
        ans.push_back(root->data);
        getLeftBoundary(root->left, ans);
    }
}

void getLeafNodes(TreeNode<int> *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
    }
    if (root->left)
    {
        getLeafNodes(root->left, ans);
    }
    if (root->right)
    {
        getLeafNodes(root->right, ans);
    }
}

void getRightBoundary(TreeNode<int> *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    else if (root->right == NULL)
    {
        ans.push_back(root->data);
        getRightBoundary(root->left, ans);
    }
    else
    {
        ans.push_back(root->data);
        getRightBoundary(root->right, ans);
    }
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> ans, temp;
    if (root == NULL)
        return ans;
    ans.push_back(root->data);

    getLeftBoundary(root->left, ans);
    getLeafNodes(root, ans);
    getRightBoundary(root->right, temp);
    reverse(begin(temp), end(temp));
    for (auto i : temp)
        ans.push_back(i);
    return ans;
}
