#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int heightChecker(const vector<int> &heights) {
        vector<int> sorted = heights;
        sort(sorted.begin(), sorted.end());
        int ans = 0, n = sorted.size();
        for (int i = 0; i < n; ++i) {
            ans += sorted[i] not_eq heights[i];
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
 * Time Complexity: O(n * log(n))
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/height-checker/description/
 * solution: https://leetcode.com/problems/height-checker/solutions/5287585/beats-100-00-of-users-with-c/
 *
 */