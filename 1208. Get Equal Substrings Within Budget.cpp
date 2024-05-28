#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int equalSubstring(const string &s, const string &t, const int &maxCost) {
        int len = s.length();
        int ans = 0;
        int l = 0;
        int mx = 0;
        for (int i = 0; i < len; ++i) {
            mx += abs(s[i] - t[i]);
            while (l <= i and mx > maxCost) {
                mx -= abs(s[l] - t[l]);
                l++;
            }
            if (mx <= maxCost)ans = max(ans, i - l + 1);
        }
        return ans;
    };
};

int main() {

    string s = "abcd", t = "bcdf";
    int maxCost = 3;
    cout << Solution().equalSubstring(s, t, maxCost);

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/get-equal-substrings-within-budget/description/
 * solution: https://leetcode.com/problems/get-equal-substrings-within-budget/solutions/5220866/beats-100-00-of-users-with-c/
 *
 */