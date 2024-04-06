#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    string minRemoveToMakeValid(string &s) {
        int open = 0, close = 0;
        for (int i = 0; i < s.length(); ++i) {
            open += (s[i] == '(');
            close += (s[i] == ')');
            if (s[i] == ')' and close > open) {
                s.erase(i, 1);
                i--;
                close--;
            }
        }
        open = close = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            open += (s[i] == ')');
            close += (s[i] == '(');
            if (s[i] == '(' and close > open) {
                s.erase(i, 1);
                if (s[i] not_eq '(')
                    i++;
                close--;
            }
        }
        return s;
    }
};

int main() {

    string s = ")))t((u)";
    cout << Solution().minRemoveToMakeValid(s);

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/
 * solution: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/solutions/4980491/beats-99-94-of-users-with-c/
 *
 */