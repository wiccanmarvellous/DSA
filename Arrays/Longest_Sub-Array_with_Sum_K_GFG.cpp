#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lenOfLongSubarr(int A[], int N, int K)
    {
        int len = 0, sum = 0;
        unordered_map<long long, int> preSumMap;
        for (int i = 0; i < N; i++)
        {
            sum += A[i];
            if (sum == K)
                len = max(len, i + 1);
            if (preSumMap.find(sum - K) != preSumMap.end())
                len = max(len, i - preSumMap[sum - K]);
            if (preSumMap.find(sum) == preSumMap.end())
                preSumMap[sum] = i;
        }
        return len;
    }
};