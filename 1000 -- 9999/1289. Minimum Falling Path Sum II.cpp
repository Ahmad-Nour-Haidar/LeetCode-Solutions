#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int minFallingPathSum(vector<vector<int>> &grid) {
        int n = grid.size();
        int ans = 0, lastC = -1;
        for (int i = 0; i < n; ++i) {
            int temp = INT_MAX;
            int last = 0;
            for (int j = 0; j < n; ++j) {
                if (j == lastC) continue;
                if (temp > grid[i][j] and j not_eq lastC) {
                    last = j;
                    temp = grid[i][j];
                }
            }
            lastC = last;
            ans += temp;
        }
        return ans;
    }
};

int main() {

    vector<vector<int>> v = {{2, 2, 1, 2, 2},
                             {2, 2, 1, 2, 2},
                             {2, 2, 1, 2, 2},
                             {2, 2, 1, 2, 2},
                             {2, 2, 1, 2, 2}};

    cout << Solution().minFallingPathSum(v);

    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n^3)
 * Space Complexity: O(n^2)
 *
 * problem: https://leetcode.com/problems/minimum-falling-path-sum-ii/description/
 * solution: https://leetcode.com/problems/minimum-falling-path-sum-ii/solutions/5074188/beats-61-21-of-users-with-c/
 *
 */