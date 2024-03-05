#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	void dfs(vector<int> adj[], vector<int> &vis, int curr, vector<int> &ans) {
	    vis[curr] = 1;
	    for (int i = 0; i < adj[curr].size(); i++) {
	        auto node = adj[curr][i];
	        if (vis[node] == 0)
	            dfs(adj, vis, node, ans);
	    }
	    ans.push_back(curr);
	}
  
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V, 0);
	    vector<int> ans;
	    for (int i = 0; i < V; i++) {
	        if (vis[i] == 0) {
	            dfs(adj, vis, i, ans);
	        }
	    }
	    reverse(ans.begin(), ans.end());
	    return ans;
	}
};