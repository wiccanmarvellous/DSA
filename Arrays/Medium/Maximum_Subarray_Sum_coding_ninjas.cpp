#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long sum = 0, mSum = arr[0];
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        mSum = max(sum, mSum);
        if (sum < 0)
            sum = 0;
    }
    if (mSum < 0)
        mSum = 0;
    return mSum;
}