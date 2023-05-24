#include <bits/stdc++.h>
using namespace std;

// Brute O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j)
                    if (nums[i] + nums[j] == target) {
                        ans.push_back(i);
                        ans.push_back(j);
                        return ans;
                    }
            }
        }
        return ans;
    }
};

// Brute O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};

// Better / Best  TC O(n log n)   SC O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash;
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int elem = target - nums[i];
            if (hash.find(elem) != hash.end() && hash[elem] != i) {
                ans.push_back(i);
                ans.push_back(hash[elem]);
                return ans;
            }
            hash[nums[i]] = i;
        }
        return ans;
    }
};

// Best     O(n + n log n)
// not work in this question because you can't change indexes while sorting, 
// prefer GFG problem for this approach, Better approach is best for this 2 Sum.

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> hash;
//         vector<int> ans;
//         int n = nums.size();
//         for (int i = 0; i < n; i++) {
//             int elem = target - nums[i];
//             if (hash.find(elem) != hash.end() && hash[elem] != i) {
//                 ans.push_back(i);
//                 ans.push_back(hash[elem]);
//                 return ans;
//             }
//             hash[nums[i]] = i;
//         }
//         return ans;
//     }
// };