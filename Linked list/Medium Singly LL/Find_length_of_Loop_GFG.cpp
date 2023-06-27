#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Brute        TC O(n)     SC O(n)
int countNodesinLoop(struct Node *head)
{
    int i = 0;
    unordered_map<Node*, int> map;
    Node *temp = head, *last = head;
    while (temp != nullptr) {
        if (map.find(temp) != map.end()) {
            return map[last] - map[temp] + 1;
        }
        i++;
        map[temp] = i;
        last = temp;
        temp = temp->next;
    }
    return 0;
}

// Optimal      TC O(n)     SC O(1)
int countNodesinLoop(struct Node *head)
{
    Node *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            int i = 0;
            do {
                i++;
                slow = slow->next;
            } while (slow != fast);
            return i;
        }
    }
    return 0;
}