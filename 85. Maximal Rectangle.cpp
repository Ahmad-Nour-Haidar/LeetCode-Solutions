#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int maximalRectangle(vector<vector<char>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int heights[m + 1];
        for (auto &it:heights)it = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            stack<int> s;
            for (int k = 0; k < m + 1; k++) {
                while (!s.empty() && heights[k] < heights[s.top()]) {
                    int h = heights[s.top()];
                    s.pop();
                    int width = s.empty() ? k : k - s.top() - 1;
                    ans = max(ans, h * width);
                }
                s.emplace(k);
            }
        }
        return ans;
    }
};

int main() {

    vector<vector<char> > v = {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
    };

    Solution().maximalRectangle(v);

    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n^3)
 * Space Complexity: O(n^2)
 *
 * problem: https://leetcode.com/problems/maximal-rectangle/description/
 * solution: https://leetcode.com/problems/maximal-rectangle/submissions/1230994590/
 *
 */