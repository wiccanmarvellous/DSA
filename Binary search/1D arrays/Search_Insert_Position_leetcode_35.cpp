#include <bits/stdc++.h>
using namespace std;

// Brute        TC O(n)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++)
            if(nums[i] == target || nums[i] > target) 
                return i;
        return nums.size();
    }
};

// Optimal      TC O(log n)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        while (s <= e) {
            int mid  = (s + e) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return s;
    }
};