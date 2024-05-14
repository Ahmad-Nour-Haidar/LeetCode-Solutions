#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n{}, m{};
    int dir[5] = {0, 1, 0, -1, 0};

    bool canMove(int i, int j, vector<vector<int>> &grid) {
        return i >= 0 and i < n and j >= 0 and j < m and grid[i][j] not_eq 0;
    }

    int dfs(int i, int j, vector<vector<int>> &grid) {
        // instead of using visited array
        int temp = grid[i][j];
        grid[i][j] = 0;
        int mx = 0;
        for (int k = 0; k < 4; k++) {
            int r = i + dir[k];
            int c = j + dir[k + 1];
            if (!canMove(r, c, grid)) {
                mx = max(mx, temp);
            } else {
                mx = max(mx, temp + dfs(r, c, grid));
            }
        }
        grid[i][j] = temp;
        return mx;
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int getMaximumGold(vector<vector<int>> &grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] not_eq 0) {
                    ans = max(ans, dfs(i, j, grid));
                }
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
 * Time Complexity: O(n * m * 4 ^ (n * m))
 * Space Complexity: O(n * m)
 *
 * problem: https://leetcode.com/problems/path-with-maximum-gold/description/
 * solution: https://leetcode.com/problems/path-with-maximum-gold/solutions/5158601/beats-70-63-of-users-with-c/
 *
 */