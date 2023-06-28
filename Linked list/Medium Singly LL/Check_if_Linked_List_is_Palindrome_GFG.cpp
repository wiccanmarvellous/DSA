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

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* reverseList(Node* head) {
        Node *temp = nullptr;
        while (head != nullptr) {
            Node *next = head->next;
            head->next = temp;
            temp = head;
            head = next;
        }
        return temp;
    }
    bool isPalindrome(Node *head)
    {
        Node *temp = head, *slow = head, *fast = head;
        int len = 0;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (len % 2 != 0)
            slow = slow->next;
        slow = reverseList(slow);
        temp = head;
        while (slow != nullptr) {
            if (temp->data != slow->data)
                return false;
            temp = temp->next;
            slow = slow->next;
        }
        return true;
    }
};