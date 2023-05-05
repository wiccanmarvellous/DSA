#include <bits/stdc++.h>
using namespace std;

// Approach 1
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         set<int> s(begin(nums), end(nums));
//         nums.clear();
//         for (auto it : s)
//             nums.push_back(it);
//         return s.size();
//      // OR
//         set<int> s;
//         for (auto it : nums)
//             s.insert(it);
//         int i = 0;
//         for (auto it : s)
//             nums[i++] = it;
//         return i;
//     }
// };

// Approach 2
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i, j = 1, n = nums.size();
        for (int i = 1; i < n; i++)
            if (nums[i] != nums[i - 1])
            {
                nums[j] = nums[i];
                j++;
            }
        return j;
    }
};

int main()
{
    vector<int> v{1, 1, 1, 2, 2, 3, 3};
    Solution obj;
    int k = obj.removeDuplicates(v);
    for (int i = 0; i < k; i++)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}