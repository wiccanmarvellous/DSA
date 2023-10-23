#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int curr) {
        visited[curr] = 1;
        for (int i = 0; i < isConnected[curr].size(); i++) {
            int node = isConnected[curr][i];
            if (node == 1 && visited[i] == 0)
                dfs(isConnected, visited, i);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int noOfProvinces = 0;
        vector<int> visited(isConnected.size(), 0);
        for (int i = 0; i < isConnected.size(); i++) {
            if (visited[i] == 0) {
                noOfProvinces++;
                dfs(isConnected, visited, i);
            }
        }
        for (auto i : visited)  cout << i << ' ';
        return noOfProvinces;
    }
};