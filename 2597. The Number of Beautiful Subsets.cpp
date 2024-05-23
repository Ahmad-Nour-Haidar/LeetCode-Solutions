#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int help(const vector<int> &nums, const int &k, int i, int *&count, const int &mx) {
        if (i == nums.size()) return 1;
        int res = help(nums, k, i + 1, count, mx);
        bool x = true;
        if (nums[i] + k < mx) {
            x = !count[nums[i] + k];
        }
        bool y = true;
        if (nums[i] - k >= 0) {
            y = !count[nums[i] - k];
        }
        if (x and y) {
            count[nums[i]] += 1;
            res += help(nums, k, i + 1, count, mx);
            count[nums[i]] -= 1;
        }
        return res;
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int beautifulSubsets(const vector<int> &nums, const int &k) {
        int mx = *max_element(nums.begin(), nums.end());
        mx++;
        int *a = new int[mx];
        for (int i = 0; i < mx; ++i) a[i] = 0;
        return help(nums, k, 0, a, mx) - 1;
    }
};

int main() {

    vector<int> v = {2, 4, 6};
    int k = 2;
    Solution().beautifulSubsets(v, k);

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(2 ^ n)
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/the-number-of-beautiful-subsets/description/
 * solution: https://leetcode.com/problems/the-number-of-beautiful-subsets/solutions/5197038/beats-66-12-of-users-with-c/
 *
 */