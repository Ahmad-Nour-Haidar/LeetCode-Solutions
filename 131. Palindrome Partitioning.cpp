#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool isPalindrome(const string &s) {
        int l = 0, r = s.length() - 1;
        while (l <= r and s[l] == s[r]) {
            l++;
            r--;
        }
        return l >= r;
    }

    void help(const string &s, vector<vector<string>> &ans, vector<string> &current) {
        if (s.empty()) ans.emplace_back(current);
        for (int i = 1; i <= s.length(); ++i) {
            string left = s.substr(0, i);
            string right = s.substr(i);
            if (isPalindrome(left)) {
                current.emplace_back(left);
                help(right, ans, current);
                current.pop_back();
            }
        }
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<vector<string>> partition(const string &s) {
        vector<vector<string>> ans;
        vector<string> v;
        help(s, ans, v);
        return ans;
    }
};

int main() {

    Solution().partition("aab");

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n * 2 ^ n)
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/palindrome-partitioning/description/
 * solution: https://leetcode.com/problems/palindrome-partitioning/solutions/5196536/beats-98-16-of-users-with-c/
 *
 */