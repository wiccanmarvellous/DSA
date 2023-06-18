#include <bits/stdc++.h>
using namespace std;

//  Iterative method        TC O(log n)
class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        int start = 0, end = n - 1;
        while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == k)
            return mid;
        else if (arr[mid] < k)
            start = mid + 1;
        else
            end = mid - 1;
        }
        return -1;
    }
};

//  Recursive method        TC O(log n)
class Solution {
  public:
    int bs(int arr[], int k, int start, int end) {
        int mid = (start + end) / 2;
        if (start > end)
            return -1;
        if (arr[mid] == k)
            return mid;
        else if (arr[mid] < k)
            return bs(arr, k, mid + 1, end);
        else
            return bs(arr, k, start, mid - 1);
    }
    int binarysearch(int arr[], int n, int k) {
        return bs(arr, k, 0, n - 1);
    }
};