#include <bits/stdc++.h>
using namespace std;

// Brute   TC O(n * n)  SC O(1)
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int n = nums.size(), count = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (nums[i] == nums[j])
//                     count++;
//             }
//             if (count == 1)
//                 return nums[i];
//             count = 0;
//         }
//         return -1;
//     }
// };


// Better   TC O((n log m / 2) + (n / 2) + 1)     SC O((n / 2) + 1)
// m = (n / 2) + 1
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         map<int, int> hash;
//         int n = nums.size();
//         for (int i = 0; i < n; i++)
//             hash[nums[i]]++;
//         for (auto it : hash)
//             if (it.second == 1)
//                 return it.first;
//         return -1;
//     }
// };


// Best     TC O(n)     SC O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), count = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] != nums[i]) {
                if (count == 1)
                    return nums[i - 1];
                else
                    count = 1;
            }
            else
                count++;
        }
        return nums.back();
    }
};

// Best     TC O(n)     SC O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int XOR = 0;
        for (auto it : nums)
            XOR = XOR ^ it;
        return XOR;
    }
};