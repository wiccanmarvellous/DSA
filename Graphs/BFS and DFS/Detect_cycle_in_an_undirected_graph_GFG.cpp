#include <bits/stdc++.h>
using namespace std;

// BFS      TC (O(n + 2E) + O(n))    SC O(n)
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        queue<pair<int, int>> q;
        for (int a = 0; a < V; a++) {
            if (vis[a] != 1) {
                q.push({a, -1});
                vis[a] = 1;
                while (!q.empty()) {
                    int q_size = q.size();
                    while (q_size--) {
                        int node = q.front().first;
                        int parent = q.front().second;
                        q.pop();
                        for (int i = 0; i < adj[node].size(); i++) {
                            int child = adj[node][i];
                            if (child != parent) {
                                if (vis[child] == 1)
                                    return 1;
                                q.push({child, node});
                                vis[child] = 1;
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
};

// DFS      TC (O(n + 2E) + O(n))    SC O(n)
class Solution {
  private:
    bool dfs(vector<int> adj[], int vis[], int node, int parent) {
        vis[node] = 1;
        for (int i = 0; i < adj[node].size(); i++) {
            int child = adj[node][i];
            if (child != parent) {
                if (vis[child] == 1)
                    return true;
                bool ans = dfs(adj, vis, child, node);
                if (ans == true)
                    return true;
            } 
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                bool ans = dfs(adj, vis, i, -1);
                if (ans == true)
                    return true;
            }
        }
        return false;
    }
};