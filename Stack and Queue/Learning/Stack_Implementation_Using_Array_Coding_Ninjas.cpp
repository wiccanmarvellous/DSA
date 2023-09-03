#include <bits/stdc++.h>
using namespace std;

// Stack class.
class Stack {

    int n, i = -1;
    int *arr;
    
public:
    
    Stack(int capacity) {
        n = capacity;
        arr = new int[capacity];
    }

    void push(int num) {
        if (!isFull()) {
            i++;
            arr[i] = num;
        }
    }

    int pop() {
        if (!isEmpty()) {
            int ans = arr[i];
            arr[i] = 0;
            i--;
            return ans;
        }
        return -1;
    }
    
    int top() {
        if (!isEmpty()) {
            return arr[i];
        }
        return -1;
    }
    
    int isEmpty() {
        if (i < 0)
            return 1;
        return 0;
    }
    
    int isFull() {
        if (i >= n - 1)
            return 1;
        return 0;
    }
    
};
