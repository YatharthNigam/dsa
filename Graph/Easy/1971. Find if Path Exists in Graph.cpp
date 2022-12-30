// https://leetcode.com/problems/find-if-path-exists-in-graph/

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        // First, we create an adjacency list using edges.
        unordered_map<int, vector<int>> adj;
        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        // Then we run BFS using queue.
        queue<int> q;
        // I made an error here. Wrote (false,n) instead of (n, false).
        vector<bool> vis(n, false);
        vis[source] = true;
        q.push(source);
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            if (curr == destination)
            {
                return true;
            }
            for (auto node : adj[curr])
            {
                if (!vis[node])
                {
                    vis[node] = true;
                    q.push(node);
                }
            }
        }
        return false;
    }
};