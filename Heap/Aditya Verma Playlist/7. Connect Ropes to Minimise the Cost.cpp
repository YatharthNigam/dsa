class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        unordered_map<int, vector<int>> m;
        int n = matches.size();
        for (int i = 0; i < n; i++)
        {
            if (m.find(matches[i][0]) == m.end())
            {
                m[matches[i][0]] = {1, 0};
            }
            else
            {
                m[matches[i][0]][0]++;
            }
            if (m.find(matches[i][1]) == m.end())
            {
                m[matches[i][1]] = {0, 1};
            }
            else
            {
                m[matches[i][1]][1]++;
            }
        }
        vector<int> one, two;
        for (auto i : m)
        {
            if (i[0] > 0 and i[1] == 0)
            {
                one.push_back(i);
            }
            else if (i[1] == 1)
            {
                two.push_back(i);
            }
        }
        sort(one.begin(), one.end());
        sort(two.begin(), two.end());
        vector<vector<int>> ans = {one, two};
        return ans;
    }
};