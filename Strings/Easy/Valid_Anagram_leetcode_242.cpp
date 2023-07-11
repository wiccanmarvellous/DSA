#include <bits/stdc++.h>
using namespace std;

// Brute        TC O(n)     SC O(2n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map_s, map_t;
        for (auto i : s)
            cout << map_s[i]++;
        for (auto i : t)
            cout << map_t[i]++;
        if (map_s != map_t)
            return false;
        return true;
    }
};