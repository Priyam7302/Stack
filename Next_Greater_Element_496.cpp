// Brute force approach using loops 
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums2.size();
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++)
        {
            bool found = false;

            for (int j = 0; j < n; j++)
            {
                if (nums1[i] == nums2[j])
                {
                    for (int k = j + 1; k < n; k++)
                    {
                        if (nums2[k] > nums2[j])
                        {
                            ans.push_back(nums2[k]);
                            found = true;
                            break;
                        }
                    }
                    break;
                }
            }

            if (!found)
                ans.push_back(-1);
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = sol.nextGreaterElement(nums1, nums2);

    for (int x : result)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
