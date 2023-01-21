// ----------1----------

class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        int ptr1 = 0, ptr2 = 0;
        while (ptr1 < nums1.size() and ptr2 < nums2.size())
        {
            if (nums1[ptr1] == nums2[ptr2])
                return nums1[ptr1];
            else if (nums1[ptr1] > nums2[ptr2])
                ptr2++;
            else
                ptr1++;
        }
        return -1;
    }
};

// ----------2----------

class Solution
{
public:
    long long minOperations(vector<int> &nums1, vector<int> &nums2, int k)
    {
        // Edge case
        if (k == 0)
        {
            for (int i = 0; i < nums1.size(); i++)
                if (nums1[i] != nums2[i])
                    return -1;
            return 0;
        }
        // If difference comes 0 then only possible.
        long long diff = 0;
        long long operations = 0;
        long long positive = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            int temp = nums1[i] - nums2[i];
            if (temp > 0)
                positive += temp;
            diff += temp;
        }
        if (diff == 0 and positive % k == 0)
            return positive / k;
        return -1;
    }
};

// ----------3----------

//---------- 4-------------

class Solution
{
public:
    bool isReachable(int targetX, int targetY)
    {
        queue<vector<int>> q;
        set<vector<int>> s;
        s.insert({1, 1});
        q.push({1, 1});
        while (!q.empty())
        {
            vector<int> currPos = q.front();
            q.pop();
            if (currPos[0] == targetX and currPos[1] == targetY)
                return true;
            vector<int> pos1 = {currPos[0], currPos[1] - currPos[0]};
            vector<int> pos2 = {currPos[0] - currPos[1], currPos[1]};
            vector<int> pos3 = {2 * currPos[0], currPos[1]};
            vector<int> pos4 = {currPos[0], 2 * currPos[1]};
            if (s.find(pos1) == s.end())
            {
                s.insert(pos1);
                q.push(pos1);
            }
            if (s.find(pos2) == s.end())
            {
                s.insert(pos2);
                q.push(pos2);
            }
            if (s.find(pos3) == s.end())
            {
                s.insert(pos3);
                q.push(pos3);
            }
            if (s.find(pos4) == s.end())
            {
                s.insert(pos4);
                q.push(pos4);
            }
        }
        return false;
    }
};