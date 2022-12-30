// ------------1------------

class Solution
{
public:
    int similarPairs(vector<string> &words)
    {
        unordered_map<string, int> m;
        for (auto i : words)
        {
            set<int> s;
            for (auto j : i)
            {
                s.insert(j);
            }
            string temp = "";
            for (auto j : s)
                temp += j;
            m[temp]++;
        }
        int cnt = 0;
        for (auto i : m)
        {
            int num = i.second;
            num = ((num) * (num - 1)) / 2;
            cnt += num;
        }
        return cnt;
    }
};

// ------------2------------

class Solution
{
public:
    vector<int> primeFactors(int n)
    {
        int c = 2;
        vector<int> f;
        while (n > 1)
        {
            if (n % c == 0)
            {
                v.push_back(c);
                n /= c;
            }
            else
                c++;
        }
        return v;
    }
    int smallestValue(int n)
    {
        while (true)
        {
            vector<int> factors = primeFactors(n);
            int sum = 0;
            for (auto i : factors)
                sum += i;
            if (sum == n)
                break;
            n = sum;
        }
        return n;
    }
};

// ------------3------------

// ------------4------------