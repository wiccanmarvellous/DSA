#include <bits/stdc++.h>
using namespace std;

// Brute force O(n1 log n + n2 log n) + O(n1 + n2)
// class Solution{
//     public:
//     vector<int> findUnion(int arr1[], int arr2[], int n, int m)
//     {
//         set<int> s;
//         for (int i = 0; i < n; i++)
//             s.insert(arr1[i]);
//         for (int j = 0; j < m; j++)
//             s.insert(arr2[j]);
//         vector<int> ans;
//         for (auto it : s)
//             ans.push_back(it);
//         return ans;
//     }
// };

// Optimal approach TC O(n1 + n2)  SC O(n1 + n2)
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> ans;
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (arr1[i] <= arr2[j])
            {
                if (ans.size() == 0 || arr1[i] != ans.back())
                    ans.push_back(arr1[i]);
                i++;
            }
            else
            {
                if (ans.size() == 0 || arr2[j] != ans.back())
                    ans.push_back(arr2[j]);
                j++;
            }
        }
        while (i < n)
        {
            if (ans.size() == 0 || arr1[i] != ans.back())
                    ans.push_back(arr1[i]);
                i++;
        }
        while (j < m)
        {
            if (ans.size() == 0 || arr2[j] != ans.back())
                    ans.push_back(arr2[j]);
                j++;
        }
        return ans;
    }
};