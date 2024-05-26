#include <bits/stdc++.h>

using namespace std;

class Solution {
    static const int mod = 1000000007;

    int help(const int &n, int i, int a, int l, int ***&dp) {
        if (a < 2 and l < 3) {
            if (i == n)
                return 1;
            if (dp[i][a][l] not_eq 0)
                return dp[i][a][l];
            int present = help(n, i + 1, a, 0, dp);
            int absent = a + 1 >= 2 ? 0 : help(n, i + 1, a + 1, 0, dp);
            int late = l + 1 >= 3 ? 0 : help(n, i + 1, a, l + 1, dp);
            return dp[i][a][l] = ((present + absent) % mod + late) % mod;
        }
        return 0;
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int checkRecord(int n) {

        int ***dp = new int **[n];

        for (int i = 0; i < n; ++i) {
            dp[i] = new int *[2];
            for (int j = 0; j < 2; ++j) {
                dp[i][j] = new int[3];
                for (int k = 0; k < 3; ++k) {
                    dp[i][j][k] = 0;
                }
            }
        }

        return help(n, 0, 0, 0, dp);
    }
};

int main() {

    cout << Solution().checkRecord(10101);
    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/student-attendance-record-ii/description/
 * solution: https://leetcode.com/problems/student-attendance-record-ii/solutions/5211585/dynamic-programming-recursion/
 *
 */