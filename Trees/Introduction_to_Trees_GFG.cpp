#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int countNodes(int i) {
        int ans = 1;
        for (int a = 1; a < i; a++) {
            ans *= 2;
        }
        return ans;
    }
};

class Solution {
  public:
    int countNodes(int i) {
        return pow(2, i - 1);
    }
};