#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void dfs(int i, vector<vector<int>> &adj, int visit[]) {
        visit[i] = 1;
        for (int j = 0; j < adj[i].size(); j++) {
            if (adj[i][j] == 1 && visit[j] == 0)
                dfs(j, adj, visit);
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        int ans = 0;
        int visit[V] = {0};
        for (int i = 0; i < adj.size(); i++) {
            if (visit[i] == 0) {
                dfs(i, adj, visit);
                ans++;
            }
        }
        return ans;
    }
};