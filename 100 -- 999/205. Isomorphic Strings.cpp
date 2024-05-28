#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    bool isIsomorphic(const string &s, const string &t) {
        int as[256], at[256], len = s.length();
        for (int i = 0; i < 256; ++i) {
            as[i] = -1;
            at[i] = -1;
        }
        for (int i = 0; i < len; ++i) {
            if (as[s[i]] not_eq at[t[i]])return false;
            as[s[i]] = i;
            at[t[i]] = i;
        }
        return true;
    }
};

int main() {

    string s = "egg", t = "add";

    cout << Solution().isIsomorphic(s, t);

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/isomorphic-strings/description/
 * solution: https://leetcode.com/problems/isomorphic-strings/solutions/4960371/beats-100-00-of-users-with-c/
 *
 */