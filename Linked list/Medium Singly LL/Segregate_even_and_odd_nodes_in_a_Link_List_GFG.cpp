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


// Brute        TC O(n)     SC O(n)
class Solution{
public:
    Node* divide(int N, Node *head){
        if (head == nullptr)
            return head;
        Node *temp = head, *odd_head = nullptr, *even_head = nullptr;
        Node *odd_temp = nullptr, *even_temp = nullptr;
        while (temp != nullptr) {
            Node *newnode = new Node(temp->data);
            if (temp->data % 2 == 0) {
                if (even_head == nullptr) 
                    even_head = even_temp =  newnode;
                else {
                    even_temp->next = newnode;
                    even_temp = newnode;
                }
            }
            else {
                if (odd_head == nullptr) 
                    odd_head = odd_temp =  newnode;
                else {
                    odd_temp->next = newnode;
                    odd_temp = newnode;
                }
            }
            temp = temp->next;
        }
        if (even_head == nullptr)
            return odd_head;
        even_temp->next = odd_head;
        return even_head;
    }
};

// Optimal      TC O(n)     SC O(1)
class Solution{
public:
    Node* divide(int N, Node *head){
        if (head == nullptr)
            return head;
        Node *o = nullptr, *e = nullptr, *oH = nullptr, *eH = nullptr, *temp = head;
        while ( temp != nullptr) {
            if (temp->data % 2 != 0) {
                if (oH == nullptr)
                    oH = temp;
                else
                    o->next = temp;
                o = temp;
            }
             else {
                if (eH == nullptr)
                    eH = temp;
                else
                    e->next = temp;
                e = temp;
            }
            temp = temp->next;
        }
        if (eH == nullptr) {
            o->next = nullptr;
            return oH;
        }
        else if (oH == nullptr) {
            e->next = nullptr;
            return eH;
        }
        o->next = nullptr;
        e->next = oH;
        return eH;
    }
};