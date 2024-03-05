#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(const vector<vector<int>>& graph, vector<int> &vis, vector<int> &colour, int curr, bool &ans) {
        vis[curr] = 1;
        for (int i = 0; i < graph[curr].size(); i++) {
            auto node = graph[curr][i];
            if (vis[node] == 0) {
                colour[node] = !colour[curr];
                dfs(graph, vis, colour, node, ans);
            }
            else {
                if (colour[node] == colour[curr])
                    ans = false;
            }
        }
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        bool ans = true;
        vector<int> colour(n, -1), vis(n, 0);
        for (int i = 0; i < graph.size(); i++) {
            if (vis[i] == 0) {
                colour[i] = 0;
                dfs(graph, vis, colour, i, ans);
            }
        }
        return ans;
    }
};