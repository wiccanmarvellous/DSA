#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(vector<int> adj[], vector<int> &ans, vector<int> &visit, int i) {
        if (visit[i] == 1)
            return;
        visit[i] = 1;
        ans.push_back(i);
        for (int j = 0; j < adj[i].size(); j++) {
            dfs(adj, ans, visit, adj[i][j]);
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans, visit(V, 0);
        dfs(adj, ans, visit, 0);
        return ans;
    }
};