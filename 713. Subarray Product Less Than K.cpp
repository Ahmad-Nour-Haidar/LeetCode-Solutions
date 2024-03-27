#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if (k == 0)return 0;
        int ans = 0, p = 1;
        int len = nums.size();
        int l = 0;
        for (int i = 0; i < len; ++i) {
            p *= nums[i];
            while (l <= i and p >= k) {
                p /= nums[l];
                l++;
            }
            ans += (i + 1 - l);
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
 * problem: https://leetcode.com/problems/subarray-product-less-than-k/description/
 * solution: https://leetcode.com/problems/subarray-product-less-than-k/solutions/4930645/beats-99-88-of-users-with-c/
 *
 */