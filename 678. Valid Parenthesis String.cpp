#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    bool checkValidString(const string &s) {
        int l1 = 0, l2 = 0;
        for (auto it:s) {
            if (it == '(') {
                l1++;
                l2++;
            } else if (it == ')') {
                l1--;
                l2--;
            } else {
                l1--;
                l2++;
            }
            if (l2 < 0) return false;
            l1 = max(l1, 0);
        }
        return l1 == 0;
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
 * problem: https://leetcode.com/problems/valid-parenthesis-string/description/
 * solution: https://leetcode.com/problems/valid-parenthesis-string/solutions/4986437/beats-100-00-of-users-with-c/
 *
 */