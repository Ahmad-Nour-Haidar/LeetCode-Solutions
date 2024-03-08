#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
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
 * problem: https://leetcode.com/problems/power-of-two/description/
 * solution: https://leetcode.com/problems/power-of-two/submissions/1179623100/
 *
 */