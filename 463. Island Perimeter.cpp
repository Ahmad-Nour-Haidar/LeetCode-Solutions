#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, m;
    int dx4[4] = {1, -1, 0, 0};
    int dy4[4] = {0, 0, 1, -1};
    bool **vis;

    bool canMove(vector<vector<int>> &grid, int i, int j) {
        return i >= 0 and i < n and j >= 0 and j < m and !vis[i][j];
    }

    bool isOnSideTop(int x) { return x == 0; }

    bool isOnSideLeft(int x) { return x == 0; }

    bool isOnSideBottom(int x) { return x == n - 1; }

    bool isOnSideRight(int x) { return x == m - 1; }

    bool isWater(vector<vector<int>> &grid, int i, int j) {
        return canMove(grid, i, j) and grid[i][j] == 0;
    }

    int dfs(vector<vector<int>> &grid, int i, int j) {
        vis[i][j] = true;
        int x = 0;
        for (int k = 0; k < 4; ++k) {
            int ii = i + dx4[k];
            int jj = j + dy4[k];

            x += isWater(grid, ii, jj);

            if (canMove(grid, ii, jj) and !isWater(grid, ii, jj)) {
                x += dfs(grid, ii, jj);
            }
        }

        x += isOnSideTop(i);
        x += isOnSideBottom(i);
        x += isOnSideLeft(j);
        x += isOnSideRight(j);

        return x;
    }

public:
    Solution() {
        n = m = 0;
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int islandPerimeter(vector<vector<int>> &grid) {
        n = grid.size();
        m = grid[0].size();
        vis = new bool *[n];
        for (int i = 0; i < n; ++i) {
            vis[i] = new bool[m];
            // Initialize each element of vis[i] to false
            for (int j = 0; j < m; ++j) {
                vis[i][j] = false;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    return dfs(grid, i, j);
                }
            }
        }
        return 0;
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
 * problem: https://leetcode.com/problems/island-perimeter/description/
 * solution: https://leetcode.com/problems/smallest-string-starting-from-leaf/solutions/5034708/8-ms-easy-short-way/
 *
 */