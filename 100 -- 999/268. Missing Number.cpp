#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int n = nums.size();
        n = n * (n + 1) / 2;
        for (auto it:nums)n -= it;
        return n;
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
 * problem: https://leetcode.com/problems/missing-number/description/
 * solution: https://leetcode.com/problems/missing-number/submissions/1180708980/
 *
 */