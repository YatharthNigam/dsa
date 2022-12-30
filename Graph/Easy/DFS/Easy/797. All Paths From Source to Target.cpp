// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution
{
public:
    void dfs(vector<vector<int>> &paths, vector<int> path, vector<vector<int>> &graph, int curr)
    {
        path.push_back(curr);
        if (curr == g.size() - 1)
            paths.push_back(path);
        for (auto i : graphs[curr])
        {
            dfs(paths, path, graph, i);
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(paths, path, graph, 0);
        return paths;
    }
};

// class Solution
// {
// public:
//     // setting a few class variables, so that we do not have to pass them down all the time in the recursive dfs calls
//     int target;
//     vector<vector<int>> paths;
//     vector<int> path;
//     void dfs(vector<vector<int>> &graph, int currNode = 0)
//     {
//         // updating path
//         path.push_back(currNode);
//         // and either updating paths with it if target is met
//         if (currNode == target)
//             paths.push_back(path);
//         // or callling dfs again recursively
//         else
//             for (int node : graph[currNode])
//             {
//                 dfs(graph, node);
//             }
//         // backtracking with path
//         path.pop_back();
//     }
//     vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
//     {
//         target = graph.size() - 1;
//         dfs(graph);
//         return paths;
//     }
// };
