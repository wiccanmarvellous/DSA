#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > nums[(i + 1) % n])
                count++;
            if (count == 2)
                return false;
        }
        return true;
    }
};

int main()
{
    vector<int> v{2, 4, 5, 1, 2};
    Solution obj;
    if (obj.check(v))
        cout << "Array is sorted and rotated." << endl;
    else
        cout << "Array is not sorted and rotated." << endl;
    return 0;
}