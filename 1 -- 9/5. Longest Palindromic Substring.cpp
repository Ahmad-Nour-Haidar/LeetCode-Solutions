#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string longestPalindrome(const string &s) {
        int n = s.size();
        if (n < 2)
            return s;

        int maxLength = 1, start = 0;
        int low, high;
        for (int i = 0; i < n; i++) {
            low = i - 1;
            high = i + 1;
            while (high < n && s[high] == s[i])high++;

            while (low >= 0 && s[low] == s[i])low--;

            while (low >= 0 && high < n && s[low] == s[high]) {
                low--;
                high++;
            }

            int length = high - low - 1;
            if (maxLength < length) {
                maxLength = length;
                start = low + 1;
            }
        }
        return s.substr(start, maxLength);
    }
};

int main() {

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/longest-palindromic-substring/description/
 * solution: https://leetcode.com/problems/longest-palindromic-substring/submissions/1180753008/
 *
 */