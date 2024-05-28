#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)return false;
        long long p = 0;
        int temp = x;
        while (temp) {
            p *= 10;
            p += (temp % 10);
            temp /= 10;
        }
        return p == x;
    }
};

int main() {

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/palindrome-number/description/
 * solution: https://leetcode.com/problems/palindrome-number/submissions/1197660698/
 *
 */