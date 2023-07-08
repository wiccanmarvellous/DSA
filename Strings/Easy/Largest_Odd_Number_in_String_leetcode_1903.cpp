#include <bits/stdc++.h>
using namespace std;

// Brute        TC O(n)     SC O(1)
class Solution {
public:
    string largestOddNumber(string num) {
        int maxOdd = 0;
        string s = "";
        for (int i = 0; i < num.length(); i++) {
            for (int j = i; j < num.length(); j++) {
                s += num[j];
                string charStr(1, num[j]);
                int x = stoi(charStr), X = stoi(s);
                if (x % 2 && X > maxOdd)
                    maxOdd = X;
            }
            s = "";
        }
        if (maxOdd)
            return to_string(maxOdd);
        return "";
    }
};

// Optimal      TC O(n)     SC O(1)
class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.length() - 1; i >= 0; i--)
            if ((num[i] - '0') % 2)
                return num.substr(0, i + 1);
        return "";
    }
};