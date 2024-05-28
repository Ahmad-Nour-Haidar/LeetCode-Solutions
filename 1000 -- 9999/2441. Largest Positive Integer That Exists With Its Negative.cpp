#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int findMaxK(vector<int> &nums) {
        int m[2001];
        for (auto &it:m) it = false;
        for (auto &it:nums)m[it + 1000] = true;
        int ans = -1;
        for (auto &it:nums) if (it > 0 and m[-it + 1000])ans = max(ans, it);
        return ans;
    }
};

int main() {
    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/
 * solution: https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/solutions/5099157/beats-99-24-of-users-with-c/
 *
 */