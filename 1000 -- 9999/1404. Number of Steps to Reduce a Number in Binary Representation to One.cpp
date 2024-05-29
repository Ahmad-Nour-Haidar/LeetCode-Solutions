#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int numSteps(string &s) {
        if (s.length() == 1) return 0;
        int ans = 0;
        int len = s.length();
        for (int i = len - 1; i > 0;) {
            if (s[i] == '0') {
                ans++;
                i--;
            } else {
                ans++;
                while (s[i] == '1' and i > 0) {
                    ans++;
                    i--;
                }
                if (i == 0)
                    ans++;
                s[i] = '1';
            }
        }
        return ans;
    }
};

int main() {
    string s = "1101";
    Solution().numSteps(s);
    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/
 * solution: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/solutions/5227556/beats-100-00-of-users-with-c/
 *
 */