#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static bool isPalindrome(string &s) {
        int n = s.length();
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] not_eq s[n - i - 1]) {
                return false;
            }
        }
        return true;
    }

public:
    string firstPalindrome(vector<string> &words) {
        string ans = "";
        for (auto it : words) {
            if (isPalindrome(it)) {
                ans = it;
                break;;
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
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/
 * solution: https://leetcode.com/problems/find-first-palindromic-string-in-the-array/submissions/1174108550/
 *
 */