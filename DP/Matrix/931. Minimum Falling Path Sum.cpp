class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &mat)
    {
        int r = mat.size();
        int c = mat[0].size();
        // For each block, we'll calculate the minimum sum to come to that block.
        // For first row, it'll be same as the values.
        for (int i = 1; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (j == 0)
                    mat[i][j] += min(mat[i - 1][j], mat[i - 1][j + 1]);
                else if (j == c - 1)
                    mat[i][j] += min(mat[i - 1][j], mat[i - 1][j - 1]);
                else
                    mat[i][j] += min(mat[i - 1][j], min(mat[i - 1][j + 1], mat[i - 1][j - 1]));
            }
        }
        int ans = INT_MAX;
        for (int j = 0; j < c; j++)
            ans = max(ans, mat[r - 1][j]);
        return ans;
    }
};