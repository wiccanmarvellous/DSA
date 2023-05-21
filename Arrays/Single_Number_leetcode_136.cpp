#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hash;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            hash[nums[i]]++;
        for (auto it : hash)
            if (it.second == 1)
                return it.first;
        return -1;
    }
};
