#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumLength(const string &s) {
        int len = s.length();
        if (len == 1)return 1;
        int l = 0, r = len - 1, c = 0;
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
                c += 2;
            } else if (l > 0 and s[l] == s[l - 1]) {
                l++;
                c++;
            } else if (r < len and s[r] == s[r + 1]) {
                r--;
                c++;
            } else break;
        }
        if ((len & 1) and (len - c) == 1 and s[(len / 2)] == s[(len / 2) - 1])c++;
        return len - c;
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
 * problem: https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/
 * solution: https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/solutions/4829215/simple-clear-solution-easy-to-understand-for-beginners-c/
 *
 */