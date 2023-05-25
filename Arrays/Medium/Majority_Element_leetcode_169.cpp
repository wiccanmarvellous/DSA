#include <bits/stdc++.h>
using namespace std;


// Brute    TC O(n * n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int count  = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[i] == nums[j])
                    count++;
            }
            if (count > nums.size() / 2)
                return nums[i];
        }
        return -1;
    }
};

// Better   TC O(n log n) + O(n)    SC O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, n = nums.size();
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++)
            hash[nums[i]]++;
        for (auto it : hash)
            if (it.second > n / 2)
                return it.first;
        return -1;
    }
};

// Best     O(n log n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return  nums[nums.size() / 2];
    }
};

// Best     TC O(n)
// Moore's voting algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), count = 0, ele = -1;
        for (int i = 0; i < n; i++) {
            if (count == 0)
                ele = nums[i];
            if (nums[i] == ele)
                count++;
            else
                count--;
        }
        return ele;
    }
};