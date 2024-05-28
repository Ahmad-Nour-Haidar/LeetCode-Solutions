#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int help(vector<vector<int>> &grid, int i, int j) {
        int ans = grid[i][j];
        for (int k = i - 1; k <= i + 1; ++k) {
            for (int l = j - 1; l <= j + 1; ++l) {
                ans = max(ans, grid[k][l]);
            }
        }
        return ans;
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<vector<int>> largestLocal(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                ans[i - 1][j - 1] = help(grid, i, j);
            }
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
 * Time Complexity: O(n^2)
 * Space Complexity: O(n^2)
 *
 * problem: https://leetcode.com/problems/largest-local-values-in-a-matrix/description/
 * solution: https://leetcode.com/problems/largest-local-values-in-a-matrix/solutions/5147040/beats-99-54-of-users-with-c/
 *
 */