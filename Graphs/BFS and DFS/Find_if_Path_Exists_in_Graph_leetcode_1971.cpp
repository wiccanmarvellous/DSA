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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> vis(n), adj[n];
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(source, adj, vis);
        for (auto i : vis)  cout << i << ' ';
        if (vis[destination] == 0)  return false;
        return true;
    }
};