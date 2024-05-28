#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    string makeGood(string &s) {
        for (int i = 1; i < s.length(); ++i) {
            if (abs(s[i] - s[i - 1]) == 32) {
                s.erase(i - 1, 2);
                i = max(i - 2, 0);

            }
        }
        return s;
    }
};

int main() {

    string s = "abBAcC";
    cout << Solution().makeGood(s);

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/make-the-string-great/description/
 * solution: https://leetcode.com/problems/make-the-string-great/solutions/4975430/beats-100-00-of-users-with-c/
 *
 */