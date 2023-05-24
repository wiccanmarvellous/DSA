#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int numsSum = 0, allSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            numsSum += nums[i];
            allSum += i + 1;
        }
        return allSum - numsSum;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0;
        for (int i = 0; i <= nums.size(); i++)
            x = x ^ i;
        for (int i = 0; i < nums.size(); i++)
            x = x ^ nums[i];
        return x;
    }
};