#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     int maxSubArray(vector<int>& nums)
//     {
//         int n = nums.size(), mSum = nums[0], sum = 0;
//         for (int i = 0; i < n; i++)
//         {
//             sum = 0;
//             for (int j = i; j < n; j++)
//             {
//                 sum += nums[j];
//                 mSum = max(sum, mSum);
//             }
//         }
//         return mSum;
//     }
// };

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int n = nums.size(), sum = 0, mSum = nums[0];
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            mSum = max(mSum, sum);
            if (sum < 0)
                sum = 0;
        }
        return mSum;
    }
};

int main()
{
    vector<int> nums{-1 };
    Solution obj;
    cout << obj.maxSubArray(nums);
}