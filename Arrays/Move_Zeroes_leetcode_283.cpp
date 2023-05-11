#include <bits/stdc++.h>
using namespace std;

// Brute force with extra space
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> temp(n, 0);
//         for (int i = 0, j = 0; i < n; i++)
//             if (nums[i] != 0)
//                 temp[j++] = nums[i];
//         for (int i = 0; i < n; i++)
//             nums[i] = temp[i];
//     }
// };

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int j = 0, n = nums.size();
//         for (int i = 0; i < n; i++) {
//             if (nums[i] != 0 && nums[j] == 0) {
//                 swap(nums[i], nums[j]);
//                 j++;
//             }
//             if (nums[j] != 0)
//                 j++;
//         }
//     }
// };

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

int main()
{
    vector<int> nums{0, 1, 0, 3, 12};
    Solution obj;
    obj.moveZeroes(nums);
    for (auto it : nums)
        cout << it << ' ';
    cout << endl;
    return 0;
}