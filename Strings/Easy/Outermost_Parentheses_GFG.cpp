#include <bits/stdc++.h>
using namespace std;

// Brute        TC O(n)     SC O(n / 2)
//  Using Stack
class Solution {
  public:
    string removeOuter(string& s) {
        string ans = "";
        stack<char> stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                if (stack.size())
                    ans += '(';
                stack.push('(');   
            }
            else {
                stack.pop();
                if (stack.size())
                    ans += ')';
            }
        }
        return ans;
    }
};

// Optimal      TC O(n)     SC O(1)
// Using counter
class Solution {
  public:
    string removeOuter(string& s) {
        int count = 0;
        string ans = "";
        for (auto it : s) {
            if (it == '(') {
                if (count > 0)
                    ans += it;
                count++;
            }
            else {
                count--;
                if (count > 0)
                    ans += it;
            }
        }
        return ans;
    }
};