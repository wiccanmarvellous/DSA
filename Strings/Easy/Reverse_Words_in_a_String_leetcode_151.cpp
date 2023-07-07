#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr;
        string str = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ')
                str += s[i];
            else if (str != "") {
                arr.push_back(str);
                str = "";
            }
        }
        if (str != "")
            arr.push_back(str);
        str = "";
        for (auto i = arr.rbegin(); i != arr.rend() - 1; i++)
            str += *i + " ";
        str += *arr.begin();
        return str;
    }
};