#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    string reverseParentheses(string &str) {
        stack<int> st;
        const int len = str.length();
        for (int i = 0; i < len; i++) {
            if (str[i] == '(') {
                st.emplace(i);
            } else if (str[i] == ')') {
                reverse(str.begin() + st.top() + 1, str.begin() + i);
                st.pop();
            }
        }
        string res;
        for (const auto &it:str) {
            if (it not_eq ')' && it not_eq '(')
                res += it;
        }
        return res;
    }
};

int main() {
    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/
 * solution: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/solutions/5458672/beats-100-00
 *
 */