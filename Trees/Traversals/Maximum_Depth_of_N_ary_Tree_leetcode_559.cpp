#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    int helper(Node* root) {
        if (root == NULL)
            return 0;
        int maxDep = 0;
        for (auto i : root->children) {
            int h = helper(i);
            maxDep = max(maxDep, h);
        }
        return maxDep + 1;
    }
    int maxDepth(Node* root) {
        return helper(root);
    }
};