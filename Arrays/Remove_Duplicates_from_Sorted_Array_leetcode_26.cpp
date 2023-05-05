#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s(begin(nums), end(nums));
        nums.clear();
        for (auto it : s)
            nums.push_back(it);
        return s.size();
    }
};

int main() {
    vector<int> v{1, 1, 1, 2, 2, 3, 3};
    Solution obj;
    int k = obj.removeDuplicates(v);
    for (int i = 0; i < k; i++)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}