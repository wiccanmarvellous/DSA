#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Solution
{
public:
    Node *constructLL(vector<int> &arr)
    {
        Node *head = NULL, *temp = NULL;
        for (int i = 0; i < arr.size(); i++)
        {
            Node *newnode = new Node(arr[i]);
            if (head == NULL)
                head = temp = newnode;
            else
            {
                temp->next = newnode;
                temp = newnode;
            }
        }
        return head;
    }
};