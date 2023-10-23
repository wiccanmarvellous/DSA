#include <bits/stdc++.h>
using namespace std;

// DFS      TC (O(n) + O(2E))   SC O(n)
class Solution
{
private:
    void dfs(vector<vector<int>> &isConnected, vector<int> &visited, int curr)
    {
        visited[curr] = 1;
        for (int i = 0; i < isConnected[curr].size(); i++)
        {
            int node = isConnected[curr][i];
            if (node == 1 && visited[i] == 0)
                dfs(isConnected, visited, i);
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int noOfProvinces = 0;
        vector<int> visited(isConnected.size(), 0);
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (visited[i] == 0)
            {
                noOfProvinces++;
                dfs(isConnected, visited, i);
            }
        }
        for (auto i : visited)
            cout << i << ' ';
        return noOfProvinces;
    }
};

// DFS with adjacency list
class Solution
{
private:
    void dfs(vector<int> adjLs[], vector<int> &vis, int curr)
    {
        vis[curr] = 1;
        for (auto i : adjLs[curr])
            if (vis[i] == 0)
                dfs(adjLs, vis, i);
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> adjLs[n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (isConnected[i][j] == 1 && i != j)
                    adjLs[i].push_back(j);

        int count = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                dfs(adjLs, vis, i);
                count++;
            }
        }
        return count;
    }
};

// BFS
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int noOfProvinces = 0;
        vector<int> visited(isConnected.size(), 0);
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (visited[i] == 0)
            {
                queue<int> q;
                q.push(i);
                noOfProvinces++;
                while (!q.empty())
                {
                    int curr = q.front();
                    q.pop();
                    visited[curr] = 1;
                    for (int i = 0; i < isConnected[curr].size(); i++)
                    {
                        if (isConnected[curr][i] == 1 && visited[i] == 0)
                        {
                            q.push(i);
                        }
                    }
                }
            }
        }
        return noOfProvinces;
    }
};

//BFS with adjacency list
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjLs[n];
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
                if (isConnected[i][j] == 1)
                    adjLs[i].push_back(j);
        
        int count = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                count++;
                queue<int> q;
                q.push(i);
                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    vis[curr] = 1;
                    for (int j = 0; j < adjLs[curr].size(); j++) {
                        int subCurr = adjLs[curr][j];
                        if (vis[subCurr] == 0) {
                            q.push(subCurr);
                        }
                    }
                }
            }
        }
        return count;
    }
};