#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int help(vector<int> &nums, int k) {
        if (k == 0)return 0;
        int ans = 0, l = 0, len = nums.size(), size = 0;
        int cnt[len + 10];
        for (auto &it:cnt)it = 0;
        for (int i = 0; i < len; ++i) {
            size += (cnt[nums[i]] == 0);
            cnt[nums[i]]++;
            while (size > k) {
                cnt[nums[l]]--;
                if (cnt[nums[l]] == 0) size--;
                l++;
            }
            ans += i - l + 1;
        }
        return ans;
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int subarraysWithKDistinct(vector<int> &nums, int k) {
        return help(nums, k) - help(nums, k - 1);
    }
};

int main() {

    vector<int> v = {1, 2, 1, 3, 4};

    cout << Solution().subarraysWithKDistinct(v, 3);

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/subarrays-with-k-different-integers/description/
 * solution: https://leetcode.com/problems/subarrays-with-k-different-integers/solutions/4944724/beats-99-96-of-users-with-c/
 *
 */