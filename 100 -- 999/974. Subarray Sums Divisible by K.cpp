#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int subarraysDivByK(const vector<int> &nums, const int &k) {
        int sum = 0, ans = 0, r;
        int m[k];
        for (int &it:m) it = 0;
        m[0] = 1;
        for (const int &num : nums) {
            sum += num;
            r = (sum % k + k) % k;
            m[r]++;
            if (m[r] > 1) {
                ans += m[r] - 1;
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
 * problem: https://leetcode.com/problems/subarray-sums-divisible-by-k/description/
 * solution: https://leetcode.com/problems/subarray-sums-divisible-by-k/solutions/5285886/beats-99-95-of-users-with-c/
 *
 */