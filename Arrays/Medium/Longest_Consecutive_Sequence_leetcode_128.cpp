#include <bits/stdc++.h>
using namespace std;

// Brute    TC O(n * n)     SC O(1)
class Solution {
public:
    bool ls(vector<int>& nums, int x) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x)
                return true;
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int len = 1,  maxLen = 1;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            while (ls(nums, x + 1) == true) {
                x += 1;
                len++;
            }
            maxLen = max(maxLen, len);
            len = 1;
        }
        return maxLen;
    }
};

// Better   TC O(n log n) + O(n)     SC O(1)
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int len = 1, max_len = 1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] + 1 == nums[i + 1])
                len++;
            else if (nums[i] == nums[i + 1])
                continue;
            else
                len = 1;
            max_len = max(max_len, len);
        }
        return max_len;
    }
};