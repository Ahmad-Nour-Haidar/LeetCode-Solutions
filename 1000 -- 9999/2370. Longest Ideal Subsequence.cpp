#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int longestIdealString(const string &s, int k) {
        int dp[150] = {}, ans = 0;
        for (auto &c : s) {
            for (int j = c - k; j <= c + k; ++j)
                dp[c] = max(dp[c], dp[j]);
            ans = max(ans, ++dp[c]);
        }
        return ans;
    }
};

int main() {

    cout << Solution().longestIdealString("eduktdb", 15);

    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/longest-ideal-subsequence/description/
 * solution: https://leetcode.com/problems/longest-ideal-subsequence/solutions/5070367/beats-83-61-of-users-with-c/
 *
 */