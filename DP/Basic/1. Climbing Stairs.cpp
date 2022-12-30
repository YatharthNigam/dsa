// https://leetcode.com/problems/climbing-stairs/description/

class Solution
{
public:
    // forgot to put & symbol while passing dp.
    int solve(int steps, vector<int> &dp)
    {
        // Base case
        if (steps == 1 || steps == 2)
            return steps;
        if (steps == 0)
            return 1;
        if (steps < 0)
            return 0;
        if (dp[steps] != -1)
            return dp[steps];
        // We can reach a step by moving one step from it's prev step or moving two steps from it's second last step.
        return dp[steps] = solve(steps - 1, dp) + solve(steps - 2, dp);
    }

    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};