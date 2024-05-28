#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int trap(vector<int> &height) {
        int len = height.size();
        int ans = 0;
        int pre[len], suf[len];
        pre[0] = height[0];
        for (int i = 1; i < len; ++i) {
            pre[i] = max(pre[i - 1], height[i]);
        }
        suf[len - 1] = height[len - 1];
        for (int i = len - 2; i >= 0; --i) {
            suf[i] = max(suf[i + 1], height[i]);
        }
        for (int i = 1; i < len - 1; ++i) {
            if (pre[i - 1] > height[i] and suf[i + 1] > height[i]) {
                ans += (min(pre[i - 1], suf[i + 1]) - height[i]);
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
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/trapping-rain-water/description/
 * solution: https://leetcode.com/problems/trapping-rain-water/solutions/5011036/beats-100-00-of-users-with-c-easy-way/
 *
 */