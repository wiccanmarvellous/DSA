#include <bits/stdc++.h>
using namespace std;

//      TC O(log n)
class Solution{
  public:
    int findFloor(vector<long long> v, long long n, long long x){
        if (x < v[0])
            return -1;
        int first = 0, last = n - 1;
        while (first <= last) {
            int mid = (first + last) / 2;
            if (v[mid] == x)
                return mid;
            else if (v[mid] < x)
                first = mid + 1;
            else
                last = mid;
        }
        return last;
    }
};