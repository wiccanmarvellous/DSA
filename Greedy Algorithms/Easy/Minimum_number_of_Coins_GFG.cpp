#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int> curr{ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        vector<int> ans;
        int n = curr.size();
        int i = n - 1, sum = 0;
        while (i >= 0 && sum < N) {
            if (curr[i] + sum > N)
                i--;
            else {
                sum += curr[i];
                ans.push_back(curr[i]);
            }
        }
        return ans;
    }
};