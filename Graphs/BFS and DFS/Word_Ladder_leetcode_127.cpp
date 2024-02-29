#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        int count = 0;
        if (s.find(endWord) == s.end())
            return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                auto [currWord, count] = q.front();
                q.pop();
                cout << currWord << endl;
                if (currWord == endWord)
                    return count;
                for (int i = 0; i < currWord.length(); i++) {
                    string tempWord = currWord;
                    for (int j = 0; j < 26; j++) {
                        tempWord[i] = 'a' + j;
                        if (s.find(tempWord) != s.end()) {
                            q.push({tempWord, count + 1});
                            s.erase(tempWord);
                        }
                    }
                }
            }
        }
        return count;
    }
};