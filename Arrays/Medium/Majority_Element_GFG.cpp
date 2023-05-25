#include <bits/stdc++.h>
using namespace std;

// Brute    O(n * n)
class Solution
{
public:
    int majorityElement(int a[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            int count = 0;
            for (int j = 0; j < size; j++)
            {
                if (a[i] == a[j])
                    count++;
            }
            if (count > size / 2)
                return a[i];
        }
        return -1;
    }
};

// Better   TC O(n)   SC O(n)
class Solution
{
public:
    int majorityElement(int a[], int size)
    {
        int count = 0;
        unordered_map<int, int> hash;
        for (int i = 0; i < size; i++)
            hash[a[i]]++;
        for (auto it : hash)
            if (it.second > size / 2)
                return it.first;
        return -1;
    }
};

class Solution
{
public:
    int majorityElement(int a[], int size)
    {
        int count = 0;
        sort(a, a + size);
        for (int i = 0; i < size; i++)
            if (a[i] == a[size / 2])
                count++;
        if (count > size / 2)
            return a[size / 2];
        return -1;
    }
};

// Best     TC O(n) + O(n)
// Moore's voting algorithm
class Solution{
  public:
    int majorityElement(int a[], int size)
    {
        int n = size, count = 0, ele = -1;
        for (int i = 0; i < size; i++) {
            if (count == 0)
                ele = a[i];
            if (a[i] == ele)
                count++;
            else
                count--;
        }
        count = 0;
        for (int i = 0; i < size; i++)
            if (ele == a[i])
                count++;
        if (count > size / 2)
            return ele;
        return -1;
    }
};