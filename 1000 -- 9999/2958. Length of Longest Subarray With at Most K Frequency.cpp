#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int maxSubarrayLength(vector<int> &nums, int k) {
        unordered_map<int, int> m;
        int l = 0, ans = 0, len = nums.size();
        for (int i = 0; i < len; ++i) {
            m[nums[i]]++;
            while (l <= i and m[nums[i]] > k) {
                m[nums[l]]--;
                l++;
            }
            ans = max(ans, i - l + 1);
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
 * problem: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/
 * solution: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/solutions/4935289/beats-99-13-of-users-with-c
 *
 */