#include <bits/stdc++.h>
using namespace std;

// Brute force
// class Solution
// {
// public:
//     int largest(vector<int> &arr, int n)
//     {
//         sort(arr.begin(), arr.end());
//         return arr[n - 1];
//     }
// };

// class Solution
// {
// public:
//     int largest(vector<int> &arr, int n)
//     {
//         return *max_element(arr.begin(), arr.end());
//     }
// };

// Optimal approach
class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        int max = arr[0];
        for (int i = 0; i < n; i++)
            if (max < arr[i])
                max = arr[i];
        return max;
    }
};

int main()
{
    vector<int> arr{1, 2, 0, 3, 2, 4, 5};
    Solution obj;
    cout << "Largest element in given array is " << obj.largest(arr, arr.size()) << endl;
    return 0;
}