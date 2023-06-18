#include <bits/stdc++.h>
using namespace std;

//  Iterative method        TC O(log n)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
        int mid = (start + end) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
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
    int bs(vector<int>& nums, int target, int start, int end) {
        int mid = (start + end) / 2;
        if (start > end)
            return -1;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            return bs(nums, target, mid + 1, end);
        else
            return bs(nums, target, start, mid - 1);
    }
    int search(vector<int>& nums, int target) {
        return bs(nums, target, 0, nums.size() - 1);
    }
};