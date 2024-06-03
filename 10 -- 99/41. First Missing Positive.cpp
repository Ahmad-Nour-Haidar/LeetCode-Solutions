#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int mex = 1;
        for (auto it:nums)if (mex == it)mex++;
        return mex;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main() {

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n log(n))
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/first-missing-positive/description/
 * solution: https://leetcode.com/problems/first-missing-positive/submissions/1214222284/
 *
 */