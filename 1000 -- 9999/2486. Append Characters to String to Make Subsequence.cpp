#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int appendCharacters(const string &s, const string &t) {
        int n = s.length();
        int m = t.length();
        int p = 0, i = 0;
        while (i < n and p < m) {
            if (s[i++] == t[p]) p++;
        }
        return m - p;
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
 * problem: https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/
 * solution: https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/solutions/5250828/beats-100-00-of-users-with-c/
 *
 */