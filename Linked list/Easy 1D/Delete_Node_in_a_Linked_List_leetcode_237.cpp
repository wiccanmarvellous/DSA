#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *t1 = node, *t2 = node->next;
        while (t2->next != NULL)
        {
            t1->val = t2->val;
            t1 = t2;
            t2 = t2->next;
        }
        t1->val = t2->val;
        t1->next = NULL;
    }
};