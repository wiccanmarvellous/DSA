#include <bits/stdc++.h>
using namespace std;


// Better   TC O(2n)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zer = 0, one = 0, two = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0) zer++;
            else if (nums[i] == 1) one++;
            else two++;
        }
        for (int i = 0; i < zer; i++) nums[i] = 0;
        for (int i = zer; i < one + zer; i++) nums[i] = 1;
        for (int i = one + zer; i < two + one + zer; i++) nums[i] = 2;
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = 0 , n = nums.size();
        while (i < n)
        {
            if (nums[i] == 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
            i++;
        }
        i = 0;
        while (i < n)
        {
            if (nums[i] == 1)
            {
                swap(nums[i], nums[j]);
                j++;
            }
            i++;
        }
    }
};

// Optimal   TC O(n)
// Dutch national flag algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
               low++, mid++;
            }
            else if (nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
            }
            else
                mid++;
        }
    }
};

