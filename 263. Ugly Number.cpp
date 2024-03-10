#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        while (n > 1 and (n % 2 == 0)) {
            n /= 2;
        }
        while (n > 1 and (n % 3 == 0)) {
            n /= 3;
        }
        while (n > 1 and (n % 5 == 0)) {
            n /= 5;
        }
        return n == 1;
    }
};

int main() {

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(log(n))
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/ugly-number/description/
 * solution: https://leetcode.com/problems/ugly-number/solutions/4851307/beats-100-00-of-users-with-c/
 *
 */