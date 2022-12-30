class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        // Creating max heap to store distances as keys.
        priority_queue<pair<int, vector<int>>> pq;

        int n = points.size();
        for (int i = 0; i < n; i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            // Pushing (distancy, (x,y))
            pq.push({x * x + y * y, {x, y}});
            // Only keeping k elements in the heap.
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while (pq.size())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};