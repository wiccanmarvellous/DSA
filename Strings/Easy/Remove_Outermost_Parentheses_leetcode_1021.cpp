#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        stack<char> stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                if (stack.size())
                    ans += '(';
                stack.push('(');   
            }
            else if (s[i] == ')') {
                stack.pop();
                if (stack.size())
                    ans += ')';
            }
        }
        return ans;
    }
};