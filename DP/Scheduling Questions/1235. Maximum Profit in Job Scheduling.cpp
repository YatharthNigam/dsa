// https://leetcode.com/problems/maximum-profit-in-job-scheduling/

// Idea: Sort jobs by end time, their thinking process should be: starting from job index cur = jobs.length - 1, we might schedule the jobs[cur] or not.

// > If we schedule jobs[cur], the problem becomes profit of jobs[cur] + max profit of scheduling jobs ending with nearest previous job index.
// > If we don't schedule jobs[cur], the problem becomes max profit of scheduling jobs ending with cur - 1.
// We choose the one giving more profits.

class Solution
{
public:
    // binary search  to find latest non overlapping interval
    int latest_non_overlap_opt(vector<vector<int>> &job, int i)
    {
        int low = 0, high = i - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (job[mid][0] <= job[i][1]) // end time is less then start time of current job.
            {
                if (job[mid + 1][0] <= job[i][1]) // increment the low. normal binary search.
                    low = mid + 1;
                else // return lower bound.
                    return mid;
            }
            else
                high = mid - 1;
        }
        return -1;
    }

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        vector<vector<int>> jobs;
        int n = startTime.size();
        for (int i = 0; i < startTime.size(); i++)
        {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        vector<int> dp(n, 0);
        // Adding as if first job is taken.
        dp[0] = jobs[0][2];

        for (int i = 1; i < n; i++)
        {
            // If ith job is not included.
            int exclusive = dp[i - 1];
            // If included
            int inclusive = jobs[i][2];
            int index = latest_non_overlap_opt(jobs, i);
            // prev job whose end time was smaller then current job start time.
            if (index != -1)
                inclusive += dp[index]; //. profit that is appearing before start time of this job.
            dp[i] = max(inclusive, exclusive);
        }
        return dp[n - 1];
    }
};