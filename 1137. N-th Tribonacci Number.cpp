#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int tribonacci(int n) {
        int a[38];
        a[0] = 0;
        a[1] = 1;
        a[2] = 1;
        for (int i = 3; i < 38; ++i) {
            a[i] = a[i - 1] + a[i - 2] + a[i - 3];
        }
        return a[n];
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
 * problem: https://leetcode.com/problems/n-th-tribonacci-number/description/
 * solution: https://leetcode.com/problems/n-th-tribonacci-number/solutions/5065553/beats-100-00-of-users-with-c/
 *
 */