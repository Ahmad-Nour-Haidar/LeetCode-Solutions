#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int maxDepth(const string &s) {
        int ans = 0, mx = 0;
        for (auto it :s) {
            mx += (it == '(');
            ans = max(ans, mx);
            mx -= (it == ')');
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
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/
 * solution: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/solutions/4969999/beats-100-00-of-users-with-c/
 *
 */