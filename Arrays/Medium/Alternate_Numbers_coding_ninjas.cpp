#include <bits/stdc++.h>
using namespace std;


// TC O(2n)     SC O(n)
vector<int> alternateNumbers(vector<int>&a) {
    int n = a.size();
    vector<int> pos, neg;
    for (auto it : a) {
        if (it > 0)
            pos.push_back(it);
        else
            neg.push_back(it);

    }
    if (pos.size() > neg.size()) {
        for (int i = 0; i < neg.size(); i++) {
            a[i * 2] = pos[i];
            a[i * 2 + 1] = neg[i];
        }
        int idx = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++)
            a[idx++] = pos[i];
    }
    else if (pos.size() < neg.size()) {
        for (int i = 0; i < pos.size(); i++) {
            a[i * 2] = pos[i];
            a[i * 2 + 1] = neg[i];
        }
        int idx = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++)
            a[idx++] = neg[i];
    }
    else {
        for (int i = 0; i < n / 2; i++) {
            a[i * 2] = pos[i];
            a[i * 2 + 1] = neg[i];
        }
    }
    return a;
}