// ----------------1---------------

class Solution {
public:
    int pivotInteger(int n) {
        vector<int> prefixSum;
        int sum = 0;
        for(int i=1; i<=n; i++) {
            sum += i;
            prefixSum[i-1] = sum;
        }
        for (int i = 0; i < n; i++)
        {
            if(prefixSum[i] == (prefixSum[n-1]-prefixSum[i]))
                return i+1;
        }
        return -1;
    }
};

2.
class Solution {
public:
    int appendCharacters(string s, string t) {
        int p1=0, p2=0;
        int cnt = 0;
        while(p1<s.size() and p2<t.size()) {
            if(s[p1] == t[p2]) {
                p2++;
            }
            p1++;
        }
        return t.size()-p2;
    }
};

// 3.
ListNode *reverseList(ListNode *headref)
{
    ListNode *current = headref;
    ListNode *prev = NULL;
    ListNode *next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return headref = prev;
}

ListNode *delLesserNodes(ListNode *head)
{
    ListNode *current = head;

    /* Initialize max */
    ListNode *maxnode = head;

    while (current != NULL &&
           current->next != NULL)
    {
        /* If current is smaller than max,
        then delete current */
        if (current->next->val < maxnode->val)
        {
            ListNode *temp = current->next;
            current->next = temp->next;
            // free(temp);
        }

        /* If current is greater than max,
            then update max and move current */
        else
        {
            current = current->next;
            maxnode = current;
        }
    }
    return head;
}

void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << " " << head->val;
        head = head->next;
    }
    cout << "\n";
}

class Solution
{
public:
    ListNode *removeNodes(ListNode *head)
    {
        if (head == NULL)
            return head;
        head = reverseList(head);
        // printList(head);
        head = delLesserNodes(head);
        head = reverseList(head);
        return head;
    }
};

// -------------4-------------------

class Solution
{
public:
    int countSubarrays(vector<int> &p, int m)
    {
        map<int, int> c;
        c[0] = 1;
        bool has = false;
        int sum = 0;
        long long ans = 0;
        int n = p.size();
        for (int r = 0; r < n; r++)
        {

            // If element is less than m
            if (p[r] < m)
                sum--;

            // If element greater than m
            else if (p[r] > m)
                sum++;

            // If m is found
            if (p[r] == m)
                has = true;

            // Count the answer
            if (has)
                ans += c[sum] + c[sum - 1];

            // Increment sum
            else
                c[sum]++;
        }

        return ans;
    }
};