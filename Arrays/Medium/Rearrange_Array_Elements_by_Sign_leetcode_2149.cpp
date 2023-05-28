#include <bits/stdc++.h>
using namespace std;

// Brute    TC O(n)     SC O(n)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for (auto it : nums) {
            if (it > 0)
                pos.push_back(it);
            else if (it < 0)
                neg.push_back(it);
        }
        int n = nums.size(), flag = 1, i = 0, j = 0, k = 0;
        while (i < n) {
            if (flag == 1) {
                nums[i++] = pos[j++];
                flag = -1;
            }
            else if (flag == -1) {
                nums[i++] = neg[k++];
                flag = 1;
            }
        }
        return nums;
    }
};