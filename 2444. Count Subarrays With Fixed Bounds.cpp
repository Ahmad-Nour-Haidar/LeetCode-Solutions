#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    long long countSubarrays(vector<int> &nums, int minK, int maxK) {
        int len = nums.size(), wrongIndex = -1, mnIndex = -1, mxIndex = -1;
        long long ans = 0;
        for (int i = 0; i < len; ++i) {
            if (nums[i] < minK or nums[i] > maxK)wrongIndex = i;
            if (nums[i] == minK)mnIndex = i;
            if (nums[i] == maxK)mxIndex = i;
            int s = min(mnIndex, mxIndex);
            if (s > wrongIndex)ans += (s - wrongIndex);
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
 * problem: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/
 * solution: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/solutions/4950572/beats-100-00-of-users-with-c/
 *
 */