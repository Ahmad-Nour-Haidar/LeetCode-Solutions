#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static bool isPalindrome(string s) {
        int n = s.length();
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] not_eq s[n - i - 1]) {
                return false;
            }
        }
        return true;
    }

public:
    int countSubstrings(const string &s) {
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                ans += isPalindrome(s.substr(i, j - i + 1));
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n * log(n))
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/palindromic-substrings/description/
 * solution: https://leetcode.com/problems/palindromic-substrings/submissions/1171424936/
 *
 */