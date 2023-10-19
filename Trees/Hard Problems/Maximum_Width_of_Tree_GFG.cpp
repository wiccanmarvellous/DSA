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

class Solution {
  public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root) {
        if (root == NULL)   return 0;
        int ans = 1;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            ans = max(ans, n);
            while (n--) {
                Node* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ans;
    }
};