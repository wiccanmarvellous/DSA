#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

// Brute        TC O(2n)    SC O(1)
Node* deleteMid(Node* head)
{
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node *del_node = nullptr, *temp = head;
    int n = 0, i = 0;
    while (temp->next != nullptr) {
        n++;
        temp = temp->next;
    }
    if (n % 2 != 0)
        n += 1;
    temp = head;
    while (i + 1 < n / 2) {
        i++;
        temp = temp->next;
    }
    del_node = temp->next;
    temp->next = temp->next->next;
    delete del_node;
    return head;
}

// Optimal      TC O(n)     SC O(1)
Node* deleteMid(Node* head)
{
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node *del_node = nullptr, *slow = head, *fast = head->next;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    del_node = slow->next;
    slow->next = slow->next->next;
    delete del_node;
    return head;
}