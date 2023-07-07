#include <bits/stdc++.h>
using namespace std;

// Brute        TC O(n * n / 2)     SC O(1)
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        string str = "", ans = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ')
                str += s[i];
            else if (str != "") {
                reverse(str.begin(), str.end());
                ans += str + " ";
                str = "";
            }
        }
        if (str != "") {
                reverse(str.begin(), str.end());
                ans += str;
        }
        if (ans[ans.length() - 1] == ' ')
            ans.resize(ans.length() - 1);
        return ans;
    }
};

//Better        TC O(n)     SC O(n)
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

// Optimal      TC O(n)     SC(1)
class Solution {
public:
    string reverseWords(string s) {
        string str = "", ans = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ')
                str += s[i];
            else if (str != "") {
                if (ans != "")
                    ans = str + " " + ans;
                else
                    ans = str;
                str = "";
            }
        }
        if (str != "") {
            if (ans != "")
                ans = str + " " + ans;
            else
                ans = str;
        }
        return ans;
    }
};