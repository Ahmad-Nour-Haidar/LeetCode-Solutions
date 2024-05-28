#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int subsetXORSum(vector<int> &nums, int i = 0, int total = 0) {
        if (i == nums.size())return total;
        return subsetXORSum(nums, i + 1, nums[i] ^ total) +
               subsetXORSum(nums, i + 1, total);
    }
};

int main() {

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(2 ^ n)
 * Space Complexity: O(2 ^ n)
 *
 * problem: https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/
 * solution: https://leetcode.com/problems/sum-of-all-subset-xor-totals/solutions/5183168/beats-100-00-of-users-with-c/
 *
 */