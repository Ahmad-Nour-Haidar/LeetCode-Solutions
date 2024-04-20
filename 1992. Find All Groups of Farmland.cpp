#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, m, brc1, brc2;
    int d[5] = {0, 1, 0, -1, 0};
    bool **vis{};

    bool canMove(vector<vector<int>> &land, int i, int j) {
        return i >= 0 and i < n and j >= 0 and j < m and !vis[i][j] and land[i][j] == 1;
    }

    bool isBottomRightCorner(vector<vector<int>> &land, int i, int j) {
        return (i == n - 1 or (i < n - 1 and j < m and land[i + 1][j] == 0)) and
               (j == m - 1 or (j < m - 1 and i < n and land[i][j + 1] == 0));
    }

    void dfs(vector<vector<int>> &land, int i, int j) {
        vis[i][j] = true;
        if (isBottomRightCorner(land, i, j)) {
            brc1 = i;
            brc2 = j;
            return;
        }
        for (int k = 0; k < 4; ++k) {
            int ii = i + d[k];
            int jj = j + d[k + 1];
            if (canMove(land, ii, jj)) {
                dfs(land, ii, jj);
            }
        }
    }

public:
    Solution() {
        n = m = brc1 = brc2 = 0;
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<vector<int>> findFarmland(vector<vector<int>> &land) {
        n = land.size();
        m = land[0].size();
        // initial vis array
        vis = new bool *[n];
        for (int i = 0; i < n; ++i) {
            vis[i] = new bool[m];
            for (int j = 0; j < m; ++j) {
                vis[i][j] = false;
            }
        }
        // start solution
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (land[i][j] and !vis[i][j]) {
                    vector<int> temp;
                    temp.emplace_back(i);
                    temp.emplace_back(j);
                    dfs(land, i, j);
                    temp.emplace_back(brc1);
                    temp.emplace_back(brc2);
                    ans.emplace_back(temp);
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
 * problem: https://leetcode.com/problems/find-all-groups-of-farmland/description/
 * solution: https://leetcode.com/problems/find-all-groups-of-farmland/solutions/5048417/115-ms/
 *
 */