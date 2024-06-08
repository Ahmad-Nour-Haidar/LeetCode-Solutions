#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    bool checkSubarraySum(const vector<int> &nums, const int &k) {
        int len = nums.size(), pre = 0;
        if (len < 2) return false;
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < len; i++) {
            pre += nums[i];
            int r = pre % k;
            bool find = m.count(r);
            if (find and (i - m[r] > 1)) {
                return true;
            } else if (!find) {
                m[r] = i;
            }
        }
        return false;
    }
};

int main() {

    vector<int> v = {5, 0, 0, 0};
    int k = 3;
    Solution().checkSubarraySum(v, k);

    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/continuous-subarray-sum/description/
 * solution: https://leetcode.com/problems/continuous-subarray-sum/solutions/5280500/beats-97-84-of-users-with-c/
 *
 */