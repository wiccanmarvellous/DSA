#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        long long sum = 0, mSum = arr[0];
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            mSum = max(mSum, sum);
            if (sum < 0)
                sum = 0;
        }
        return mSum;
    }
};

int main()
{
    int arr[] = {1,2,3,-2,5};
    Solution obj;
    cout << obj.maxSubarraySum(arr, 5);
}