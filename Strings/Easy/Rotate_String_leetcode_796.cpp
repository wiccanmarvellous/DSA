#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length())
            return false;
        s += s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == goal[0]) {
                int j = 0, k = i;
                while (s[i] == goal[j]) {
                    if (j == goal.length() - 1)
                        return true;
                    i++;
                    j++;
                }
                i = k;
            }
        }
        return false;
    }
};