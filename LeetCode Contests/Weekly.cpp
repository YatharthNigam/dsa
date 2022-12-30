// -------------1-----------------

class Solution
{
public:
    int deleteGreatestValue(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            sort(grid[i].begin(), grid[i].end(), greater<int>);
        }
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            int currMax = INT_MIN;
            for (int j = 0; j < grid[0].size(); j++)
            {
                currMax = max(grid[j][i], currMax);
            }
            ans += currMax;
        }
        return ans;
    }
};

// ----------------2----------------

class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {
        unordered_map<int, int> m;
        for (auto i : nums)
        {
            m[i]++;
        }
        int maxCnt = -1;
        for (auto i : nums)
        {
            if(i>3037000499) {
                continue;
            }
            long long temp = (long long) i * i;
            if (m.find(temp) != m.end())
            {
                long long curr = i;
                int cnt = 0;
                while (m.find(curr) != m.end())
                {
                    cnt++;
                    if(curr>3037000499) {
                        break;
                    }
                    curr *= curr;
                }
                maxCnt = max(maxCnt, cnt);
            }
        }
        return maxCnt;
    }
};

// ---------------3----------------------

class Allocator
{
public:
    unordered_map<int, int> m;
    int len = 0;
    int maxLen;
    Allocator(int n)
    {
        maxLen = n;
    }

    int allocate(int size, int mID)
    {
        if (len + size < len)
        {
            while (size--)
            {
                m[mID]++;
                len++;
            }
        }
        else 
            return -1;
    }

    int free(int mID)
    {
        if(m.find(mID) != m.end()) {
            int num = m[mID];
            m.erase(mID);
            return num;
        }
        return 0;
    }
};