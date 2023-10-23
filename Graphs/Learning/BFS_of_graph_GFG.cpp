#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
       vector<int> ans, visit(V, 0);
       queue<int> q;
       q.push(0);
       visit[0] = 1;
       while (!q.empty()) {
           int i = q.front();
           q.pop();
           ans.push_back(i);
           for (int j = 0; j < adj[i].size(); j++) {
               int node = adj[i][j];
               if (visit[node] == 0) {
                   q.push(node);
                   visit[node] = 1;
               }
           }
       }
       return ans;
    }
};