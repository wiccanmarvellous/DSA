#include <bits/stdc++.h>
using namespace std;



struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};

//Function to push an element into the queue.
void MyQueue:: push(int x)
{
    QueueNode *node = new QueueNode(x);
    if (rear != NULL)
        rear->next = node;
    else 
        front = node;
    rear = node;
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
    if (front == NULL)
        return -1;
    int ans = front->data;
    if (front == rear)
        front = rear = NULL;
    else
        front = front->next;
    return ans;
}