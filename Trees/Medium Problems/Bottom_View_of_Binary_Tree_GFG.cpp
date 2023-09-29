#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

//  TC O(n)     SC O(n)

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        queue<pair<Node*, int>> q;
        map<int, int> dict;
        q.push({root, 0});
        while (!q.empty()) {
            Node *node = q.front().first;
            int idx = q.front().second;
            q.pop();
            dict[idx] = node->data;
            if (node->left) q.push({node->left, idx - 1});
            if (node->right) q.push({node->right, idx + 1});
        }
        vector<int> ans;
        for (auto i : dict)
            ans.push_back(i.second);
        return ans;
    }
};