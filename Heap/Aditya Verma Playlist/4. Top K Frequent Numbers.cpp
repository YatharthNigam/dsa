// https://leetcode.com/problems/top-k-frequent-elements/

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // creating a map to count frequency or numbers.
        map<int, int> m;
        for (auto i : nums)
        {
            m[i]++;
        }
        // Creating a min heap and pushing numbers with frequency as key to sort them based on keys.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto i : m)
        {
            pq.push({i.second, i.first});
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};