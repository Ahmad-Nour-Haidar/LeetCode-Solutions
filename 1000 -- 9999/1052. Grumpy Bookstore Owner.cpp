#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, const int &minutes) {
        int n = customers.size();
        int pre[n], validPre[n];
        pre[0] = customers[0];
        validPre[0] = 0;
        if (!grumpy[0])validPre[0] = customers[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i - 1] + customers[i];
            validPre[i] = validPre[i - 1];
            if (!grumpy[i])validPre[i] += customers[i];
        }
        int ans = 0;
        for (int i = 0; i <= n - minutes; ++i) {
            int l = i > 0 ? i - 1 : 0;
            int r = i + minutes - 1;
            int left = 0;
            if (i) left = validPre[l];
            int mid = pre[r];
            if (i)mid -= pre[l];
            int right = validPre[n - 1] - validPre[r];
            ans = max(ans, left + mid + right);
        }
        return ans;
    }
};

int main() {

    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int m = 3;
    cout << Solution().maxSatisfied(customers, grumpy, m);


    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/grumpy-bookstore-owner/description/
 * solution: https://leetcode.com/problems/grumpy-bookstore-owner/solutions/5347313/beats-99-25/
 *
 */