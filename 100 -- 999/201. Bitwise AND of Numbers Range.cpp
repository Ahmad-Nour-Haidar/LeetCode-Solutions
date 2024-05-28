#include <bits/stdc++.h>

using namespace std;


class Solution {
//    Time Complexity: O(log(max(left, right)))
//    Auxiliary Space: O(1)
private:
    // Find position of MSB in n. For example if n = 17,
    // then position of MSB is 4. If n = 7, value of MSB
    // is 2
    static int msbPos(long long n) {
        int msb_p = -1;
        while (n) {
            n = n >> 1;
            msb_p++;
        }
        return msb_p;
    }

public:
    int rangeBitwiseAnd(int left, int right) {
        int res = 0;

        while (left && right) {
            // Find positions of MSB in x and y
            int msb_p1 = msbPos(left);
            int msb_p2 = msbPos(right);

            // If positions are not same, return
            if (msb_p1 != msb_p2)
                break;

            // Add 2^msb_p1 to result
            int msb_val = (1 << msb_p1);
            res = res + msb_val;

            // subtract 2^msb_p1 from x and y.
            left -= msb_val;
            right -= msb_val;
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
 * Time Complexity: O(log(max(left, right)))
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
 * solution: https://leetcode.com/problems/bitwise-and-of-numbers-range/submissions/1181706992/
 *
 */