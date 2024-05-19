#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges) {
        int n = nums.size();
        int a[n];
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += nums[i];
            a[i] = (nums[i] ^ k) - nums[i];
        }
        sort(a, a + n, greater<>());
        for (int i = 0; i < n - 1; i += 2) {
            long long x = a[i] + a[i + 1];
            if (x <= 0)break;
            ans += x;
        }
        return ans;
    }
};

int main() {

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n * log(n))
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/find-the-maximum-sum-of-node-values/description/
 * solution: https://leetcode.com/problems/find-the-maximum-sum-of-node-values/solutions/5181393/beats-100-00-of-users-with-c/
 *
 */