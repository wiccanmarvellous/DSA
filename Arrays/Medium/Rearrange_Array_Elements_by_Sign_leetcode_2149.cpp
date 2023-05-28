#include <bits/stdc++.h>
using namespace std;

// Brute    TC O(n * (n / 2))   SC O(n)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size(), pos = 0, neg = 0, i = 0, flag = 1;
        while (i < n)
        {
            if (flag == 1) {
                while (nums[pos] < 0)
                    pos++;
                ans.push_back(nums[pos]);
                pos++;
                flag = -1;
            }
            else if (flag == -1) {
                while (nums[neg] > 0) 
                    neg++;
                ans.push_back(nums[neg]);
                neg++;
                flag = 1;
            }
            i++;
        }
        return ans;
    }
};

// Better    TC O(n + (n / 2))     SC O(n)
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
        int n = nums.size();
        for (int i = 0; i < n / 2; i++) {
            nums[i * 2] = pos[i];
            nums[i * 2 + 1] = neg[i];
        }
        return nums;
    }
};
// OR
// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         vector<int> ans;
//         int n = nums.size(), pos = 0, neg = 0, i = 0, flag = 1;
//         while (i < n)
//         {
//             if (flag == 1) {
//                 while (nums[pos] < 0)
//                     pos++;
//                 ans.push_back(nums[pos]);
//                 pos++;
//                 flag = -1;
//             }
//             else if (flag == -1) {
//                 while (nums[neg] > 0) 
//                     neg++;
//                 ans.push_back(nums[neg]);
//                 neg++;
//                 flag = 1;
//             }
//             i++;
//         }
//         return ans;
//     }
// };


// Optimal      TC O(n)     SC O(n)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), pos = 0, neg = 1;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans[pos] = nums[i];
                pos += 2;
            }
            else {
                ans[neg] = nums[i];
                neg += 2;
            }
        }
        return ans;
    }
};