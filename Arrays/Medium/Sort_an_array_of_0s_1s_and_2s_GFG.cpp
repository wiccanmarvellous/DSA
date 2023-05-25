#include <bits/stdc++.h>
using namespace std;

// Better   TC O(2n)
class Solution
{
public:
    void sort012(int a[], int n)
    {
        int zer = 0, one = 0, two = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
                zer++;
            else if (a[i] == 1)
                one++;
            else
                two++;
        }
        for (int i = 0; i < zer; i++)
            a[i] = 0;
        for (int i = zer; i < one + zer; i++)
            a[i] = 1;
        for (int i = one + zer; i < two + one + zer; i++)
            a[i] = 2;
    }
};

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int i = 0, j = 0;
        while (i < n)
        {
            if (a[i] == 0)
            {
                swap(a[i], a[j]);
                j++;
            }
            i++;
        }
        i = 0;
        while (i < n)
        {
            if (a[i] == 1)
            {
                swap(a[i], a[j]);
                j++;
            }
            i++;
        }
    }
    
};

// Optimal   TC O(n)
// Dutch national flag algorithm
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high) {
            if (a[mid] == 0) {
                swap(a[mid], a[low]);
                low++, mid++;
            }
            else if (a[mid] == 2) {
                swap(a[mid], a[high]);
                high--;
            }
            else
                mid++;
        }
    }
    
};