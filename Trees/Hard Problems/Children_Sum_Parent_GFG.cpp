#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    void helper(Node *root, int &ans) {
        if (root == NULL || ans == 0 || (!root->left && !root->right))
            return;
        int l, r;
        l = root->left != NULL ? root->left->data : 0;
        r = root->right != NULL ? root->right->data : 0;
        if (l + r != root->data)
            ans = 0;
        else {
            helper(root->left, ans);
            helper(root->right, ans);
        }
    }
    int isSumProperty(Node *root)
    {
     // Add your code here
     int ans = 1;
     helper(root, ans);
     return ans;
    }
};