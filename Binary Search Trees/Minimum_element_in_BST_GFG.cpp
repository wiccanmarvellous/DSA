#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

int minValue(Node* root) {
    if (root == NULL)
        return -1;
    while (root->left != NULL)
        root = root->left;
    return root->data;
}