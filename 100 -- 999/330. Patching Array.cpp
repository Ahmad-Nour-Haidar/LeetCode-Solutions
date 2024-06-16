#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int minPatches(const vector<int> &nums, const int &n) {
        long long s = 1;
        int ans = 0, len = nums.size(), i = 0;
        while (s <= n) {
            if (i < len && nums[i] <= s) {
                s += nums[i];
                i++;
            } else {
                s += s;
                ans++;
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
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/patching-array/description/
 * solution: https://leetcode.com/problems/patching-array/solutions/5320326/beats-100-00/
 *
 */