// https://leetcode.com/problems/house-robber/description/

// Best explanation
// https://leetcode.com/problems/house-robber/solutions/156523/from-good-to-great-how-to-approach-most-of-dp-problems/?orderBy=most_votes

// Recursive:

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        return rob(nums, nums.size() - 1);
    }

    int rob(vector<int> &num, int i)
    {
        if (i < 0)
            return 0;
        // Either select last element+max from array excluding second last.
        // Or select from second last and same.
        return max(num[i] + rob(num, i - 2), rob(num, i - 1));
    }
};

// Recursive + Memo. (Top Down)

class Solution
{
public:
    vector<int> dp;
    int rob(vector<int> &nums)
    {
        dp.resize(nums.size(), -1);
        return rob(nums, nums.size() - 1);
    }

    int rob(vector<int> &num, int i)
    {
        if (i < 0)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        // Either select last element+max from array excluding second last.
        // Or select from second last and same.
        return dp[i] = max(num[i] + rob(num, i - 2), rob(num, i - 1));
    }
};

// Recursive + Memo (Bottom Up)
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 1; i < n; i++)
        {
            int temp = nums[i];
            dp[i + 1] = max(dp[i], dp[i - 1] + temp);
        }
        return dp[n - 1];
    }
};

// Two variables
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int prev1 = 0;
        int prev2 = 0;
        for (int num : nums)
        {
            int tmp = prev1;
            prev1 = max(prev2 + num, prev1);
            prev2 = tmp;
        }
        return prev1;
    }
};