#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<int> luckyNumbers(const vector<vector<int>> &matrix) {
        vector<int> luckyNumbers;
        const int m = matrix.size();
        const int n = matrix[0].size();

        // Find the minimum element in each row
        int rowMins[m];
        for (int &it:rowMins)it = INT_MAX;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] < rowMins[i]) {
                    rowMins[i] = matrix[i][j];
                }
            }
        }

        // Find the maximum element in each column
        int colMaxs[n];
        for (int &it:colMaxs)it = INT_MIN;
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                if (matrix[i][j] > colMaxs[j]) {
                    colMaxs[j] = matrix[i][j];
                }
            }
        }

        // Check for lucky numbers
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == rowMins[i] and matrix[i][j] == colMaxs[j]) {
                    luckyNumbers.emplace_back(matrix[i][j]);
                }
            }
        }

        return luckyNumbers;
    }
};

int main() {
    return 0;
}


/**╧
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n * m)
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/
 * solution: https://leetcode.com/problems/lucky-numbers-in-a-matrix/solutions/5499016/beats-98-54
 *
 */