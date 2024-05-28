#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, m;
    int d[5] = {0, 1, 0, -1, 0};
    bool **vis{};

    bool canMove(vector<vector<char>> &grid, int i, int j) {
        return i >= 0 and i < n and j >= 0 and j < m and !vis[i][j] and grid[i][j] == '1';
    }

    void dfs(vector<vector<char>> &grid, int i, int j) {
        vis[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int ii = i + d[k];
            int jj = j + d[k + 1];
            if (canMove(grid, ii, jj)) {
                dfs(grid, ii, jj);
            }
        }
    }

public:
    Solution() {
        n = m = 0;
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int numIslands(vector<vector<char>> &grid) {
        n = grid.size();
        m = grid[0].size();
        // initial vis array
        vis = new bool *[n];
        for (int i = 0; i < n; ++i) {
            vis[i] = new bool[m];
            for (int j = 0; j < m; ++j) {
                vis[i][j] = false;
            }
        }
        // start solution
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1' and !vis[i][j]) {
                    ans++;
                    dfs(grid, i, j);
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
 * Time Complexity: O(n * m)
 * Space Complexity: O(n * m)
 *
 * problem: https://leetcode.com/problems/number-of-islands/description/
 * solution: https://leetcode.com/problems/number-of-islands/solutions/5044104/beats-99-22-of-users-with-c/
 *
 */