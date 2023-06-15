#include <bits/stdc++.h>
using namespace std;

// Brute        TC O(n * n)     SC O(n)
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0, len = 0;
            for (int j = i; j < n; j++) {
                sum += A[j];
                len++;
                if (sum == 0)
                    maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};

// Optimal      TC O(n)     SC O(n)
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int sum = 0, len = 0;
        unordered_map<int, int> hashmap;
        for (int i = 0; i < n; i++) {
            sum += A[i];
            if (sum == 0) {
                len = i + 1;
            }
            else {
                if (hashmap.find(sum) != hashmap.end())
                    len = max(len, i - hashmap[sum]);
                else
                    hashmap[sum] = i;
            }
        }
        return len;
    }
};