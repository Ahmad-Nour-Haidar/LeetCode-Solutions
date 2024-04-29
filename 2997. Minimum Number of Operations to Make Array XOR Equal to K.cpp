#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int minOperations(vector<int> &nums, int k) {
        int ans = 0;
        for (auto it :nums)ans ^= it;
        ans ^= k;
        return __builtin_popcount(ans);
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
 * problem: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/description/
 * solution: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/solutions/5086191/beats-100-00-of-users-with-c/
 *
 */