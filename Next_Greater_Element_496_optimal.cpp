#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> st;
        unordered_map<int, int> mp; // value -> next greater
        vector<int> ans;

        // Step 1: Process nums2 using monotonic stack
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }

            if (st.empty())
                mp[nums2[i]] = -1;
            else
                mp[nums2[i]] = st.top();

            st.push(nums2[i]);
        }

        // Step 2: Build answer for nums1
        for (int x : nums1)
        {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};
