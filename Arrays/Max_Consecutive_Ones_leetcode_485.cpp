#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                count += 1;
            else
            {
                maxCount = max(maxCount, count);
                count = 0;
            }
        }
        maxCount = max(maxCount, count);
        return maxCount;
    }
};