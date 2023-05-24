#include <bits/stdc++.h>
using namespace std;

// Using extra array space
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> temp(n);
//         for (int i = 0; i < n; i++)
//             temp[i] = nums[i];
//         for (int i = 0; i < n; i++)
//             nums[i] = temp[(i + k + 1) % n];
//     }
// };

// Reversing 2 subarrays
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // if k > n (4>3) then till 3 rounds no change only 1 round to do
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + (n - (n - k)));
        reverse(nums.begin() + k, nums.end());
    }
};

int main()
{
    vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    Solution obj;
    obj.rotate(nums, k);
    for (auto it : nums)
        cout << it << ' ';
    cout << endl;
    return 0;
}