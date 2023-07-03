#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

class Solution
{
public:
    Node *getTail(Node *head) {
        Node *tail = head;
        while (tail->next)
            tail = tail->next;
        return tail;
    }
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int, int>> ans;
        Node *tail = getTail(head);
        while (head != tail) {
            int sum = head->data + tail->data;
            if (sum == target) {
                ans.push_back({head->data, tail->data});
                head = head->next;
            }
            else if (sum < target) 
                head = head->next;
            else
                tail = tail->prev;
        }
        return ans;
    }
};