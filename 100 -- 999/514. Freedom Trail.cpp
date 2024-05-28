#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int lenKey{}, lenRing{};
    int dp[100][100]{};

    int solve(const string &ring, const string &key, int r, int k) {
        if (k == lenKey)return 0;
        if (dp[r][k] not_eq 0)return dp[r][k];
        int res = INT_MAX;
        for (int i = 0; i < lenRing; ++i) {
            if (ring[i] == key[k]) {
                int min_dist = min(abs(r - i), lenRing - abs(r - i));
                res = min(res, min_dist + 1 + solve(ring, key, i, k + 1));
            }
        }
        return dp[r][k] = res;
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int findRotateSteps(const string &ring, const string &key) {
        lenRing = ring.length();
        lenKey = key.length();
        return solve(ring, key, 0, 0);
    }
};

int main() {


    string s = "godding";
    cout << s.substr(0, 4) << endl;
    cout << s.substr(4, 3) << endl;
    string ring = "edcba";
    string key = "abcde";

    cout << Solution().findRotateSteps(ring, key);

    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(n^2)
 *
 * problem: https://leetcode.com/problems/freedom-trail/description/
 * solution: https://leetcode.com/problems/freedom-trail/solutions/5079274/beats-78-30-of-users-with-c/
 *
 */