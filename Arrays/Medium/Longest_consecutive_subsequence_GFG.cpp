#include <bits/stdc++.h>
using namespace std;

// Better   TC O(n log n) + O(n)     SC O(1)
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        if (N == 0)
            return 0;
        int len = 1, maxLen = 1;
        sort(arr, arr + N);
        for (int i = 0; i < N - 1; i++) {
            if (arr[i] + 1 == arr[i + 1])
                len++;
            else if (arr[i] + 1 != arr[i + 1] && arr[i] != arr[i + 1])
                len = 1;
            maxLen = max(len, maxLen);
        }
        return maxLen;
    }
};

// Optimal     TC O(n + 2n)      SC O(n)
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        unordered_set<int> st;
        for (int i = 0; i < N; i++)
            st.insert(arr[i]);
        int maxLen = 0;
        for (auto it : st)
        {
            if (st.find(it - 1) == st.end())
            {
                int x = it, len = 1;
                while (st.find(x + 1) != st.end())
                    x++, len++;
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};