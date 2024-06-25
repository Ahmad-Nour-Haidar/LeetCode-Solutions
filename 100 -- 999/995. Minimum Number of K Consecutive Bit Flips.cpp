#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int minKBitFlips(vector<int> &nums, const int &k) {
        int n = nums.size(), ans = 0;
        int a[n + 1];
        for (int &i : a) i = 0;
        for (int i = 0; i < n; ++i) {
            if (i) a[i] += a[i - 1];
            nums[i] += a[i];
            nums[i] %= 2;
            if (i + k <= n and !nums[i]) {
                a[i]++;
                nums[i]++;
                ans++;
                a[i + k]--;
            }
        }
        return count(nums.begin(), nums.end(), 1) == n ? ans : -1;
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
 * problem: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/
 * solution: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/solutions/5365508/beats-100-00/
 *
 */