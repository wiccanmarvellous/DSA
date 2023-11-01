#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
  public:
    bool isBSTTraversal(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] >= nums[i + 1])
                return false;
        return true;
    }
};