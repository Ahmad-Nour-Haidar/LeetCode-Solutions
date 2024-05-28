#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPalindrome(const string &s) {
        int a[123] = {};
        for (auto it :s)a[it]++;
        int ans = 0;
        bool one = false;
        for (auto it :a) {
            ans += (it - (it & 1));
            one |= (it & 1);
        }
        return ans + one;
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
 * problem: https://leetcode.com/problems/longest-palindrome/description/
 * solution: https://leetcode.com/problems/longest-palindrome/solutions/4840749/beats-100-00-of-users-with-c-easy/
 *
 */