#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int arr_s[256] = {}, arr_t[256] = {};
        for (int i = 0; i < s.length(); i++) {
            if (arr_s[s[i]] != arr_t[t[i]])
                return false;
            arr_s[s[i]] = i + 1;
            arr_t[t[i]] = i + 1;
        }
        return true;
    }
};