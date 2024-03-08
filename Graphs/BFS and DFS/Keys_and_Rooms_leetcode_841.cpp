#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int curr, vector<int> adj[], vector<int> &vis) {
        vis[curr] = 1;
        for (auto i : adj[curr])
            if (vis[i] == 0)
                dfs(i, adj, vis);
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n), adj[n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < rooms[i].size(); j++)
                adj[i].push_back(rooms[i][j]);
        dfs(0, adj, vis);
        for (auto i : vis)
            if (i == 0)
                return false;
        return true;
    }
};