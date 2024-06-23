#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int longestSubarray(vector<int> &nums, const int &limit) {
        int ans = 0, j = 0, n = nums.size();
        deque<int> minQueue, maxQueue;
        for (int i = 0; i < n; ++i) {
            while (!minQueue.empty() && minQueue.back() > nums[i]) {
                minQueue.pop_back();
            }
            minQueue.push_back(nums[i]);
            while (!maxQueue.empty() && maxQueue.back() < nums[i]) {
                maxQueue.pop_back();
            }
            maxQueue.push_back(nums[i]);
            if (maxQueue.front() - minQueue.front() <= limit) {
                ans = max(ans, i - j + 1);
            } else {
                if (maxQueue.front() == nums[j]) {
                    maxQueue.pop_front();
                }
                if (minQueue.front() == nums[j]) {
                    minQueue.pop_front();
                }
                j++;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> v = {4, 2, 2, 2, 4, 4, 2, 2};
    int limit = 0;

    cout << Solution().longestSubarray(v, limit);

    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/
 * solution: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/solutions/5357117/beats-99-83
 *
 */