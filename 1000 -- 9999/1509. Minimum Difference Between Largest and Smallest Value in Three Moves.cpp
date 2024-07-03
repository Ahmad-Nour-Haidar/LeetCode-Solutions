#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int minDifference(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        int ans = 0;
        if (n >= 5) {
            ans = 2e9;
            for (int i = 0; i < 4; ++i) {
                ans = min(ans, nums[n - (3 - i) - 1] - nums[i]);
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n * log(n))
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/
 * solution: https://leetcode.com/problems/height-checker/solutions/5287585/beats-100-00-of-users-with-c/
 *
 */