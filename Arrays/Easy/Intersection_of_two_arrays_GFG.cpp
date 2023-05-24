#include <bits/stdc++.h>
using namespace std;


// Optimal O(n1 + n2)
class Solution {
  public:
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        int i = 0, j = 0, count = 0, t = -1;
        sort(a, a + n);
        sort(b, b + m);
        while (i < n && j < m)
        {
            if (a[i] == b[j] && (a[i] != t || t == -1))
            {
                t = a[i];
                count++;
                i++;
                j++;
            }
            else if (a[i] < b[j])
                i++;
            else
                j++;
        }
        return count;
    }
};