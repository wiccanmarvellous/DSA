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

// Optimal      TC O(n)     SC O(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        for (auto i : s)
            cout << map[i]++;
        for (auto i : t)
            cout << map[i]--;
        for (auto i : map)
            if (i.second != 0)
                return false;
        return true;
    }
};

//  Optimal     TC O(n log n)       SC O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i = 0; i < s.length(); i++)
            if (s[i] != t[i])
                return false;
        return true;
    }
};