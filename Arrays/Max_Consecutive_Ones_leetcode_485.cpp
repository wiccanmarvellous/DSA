#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = 0, maxLen = 0, i = 0, n = nums.size();
        while (i < n)
        {
            if (nums[i] == 0)
                len = 0;
            else
            {
                len++;
                maxLen = max(maxLen, len);
            }
            i++;
        }
        return maxLen;
    }
};