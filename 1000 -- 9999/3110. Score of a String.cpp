#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int scoreOfString(const string &s) {
        int ans = 0;
        int len = s.length();
        for (int i = 1; i < len; ++i) {
            ans += abs(s[i] - s[i - 1]);
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
 * problem: https://leetcode.com/problems/score-of-a-string/description/
 * solution: https://leetcode.com/problems/score-of-a-string/solutions/5241628/beats-100-00-of-users-with-c/
 *
 */