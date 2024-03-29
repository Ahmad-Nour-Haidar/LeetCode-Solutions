#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    long long countSubarrays(vector<int> &nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        int len = nums.size(), l = 0, mxcnt = 0;
        long long ans = 0;
        for (int i = 0; i < len; ++i) {
            mxcnt += (nums[i] == mx);
            while (mxcnt == k) {
                mxcnt -= (nums[l] == mx);
                l++;
            }
            ans += l;
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
 * problem: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/
 * solution: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/solutions/4941241/beats-100-00-of-users-with-c/
 *
 */