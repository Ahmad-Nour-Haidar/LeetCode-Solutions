#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int specialArray(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i <= n; ++i) {
            int firstIndex = lower_bound(nums.begin(), nums.end(), i) - nums.begin();
            if (i == n - firstIndex) {
                return i;
            }
        }
        return -1;
    }
};

int main() {

    vector<int> v = {0, 4, 3, 0, 4};

    Solution().specialArray(v);

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n * log(n))
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/
 * solution: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/solutions/5215079/beats-100-00-of-users-with-c/
 *
 */