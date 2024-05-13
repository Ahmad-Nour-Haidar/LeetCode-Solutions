#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int matrixScore(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            // only rows the start of 0
            if (grid[i][0] == 0) {
                for (int j = 0; j < m; ++j) {
                    grid[i][j]++;
                    grid[i][j] %= 2;
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < m; ++j) {
            int zero = 0, one = 0;
            for (int i = 0; i < n; ++i) {
                grid[i][j] == 0 ? zero++ : one++;
            }
            int mx = max(zero, one);
            ans += mx * pow(2, m - j - 1);
        }
        return ans;
    }
};

int main() {

    vector<vector<int>> v = {
            {0, 1},
            {0, 1},
            {0, 1},
            {0, 0},
    };
    cout << Solution().matrixScore(v);

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n * m)
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/score-after-flipping-matrix/description/
 * solution: https://leetcode.com/problems/score-after-flipping-matrix/solutions/5150646/beats-100-00-of-users-with-c/
 *
 */