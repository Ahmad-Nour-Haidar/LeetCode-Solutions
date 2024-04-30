#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    long long wonderfulSubstrings(const string &word) {
        long long ans = 0, mask = 0;
        unordered_map<long long, int> mp;
        mp[0] = 1;
        for (auto &it:word) {
            int val = (1 << (it - 'a'));
            mask ^= val;
            ans += mp[mask];
            for (int j = 0; j < 10; j++) {
                int new_mask = mask ^(1 << j);
                ans += mp[new_mask];
            }
            mp[mask]++;
        }
        return ans;
    }
};

int main() {

    Solution().wonderfulSubstrings("adad");

    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(2^10) => O(1024)
 *
 * problem: https://leetcode.com/problems/number-of-wonderful-substrings/description/
 * solution: https://leetcode.com/problems/number-of-wonderful-substrings/solutions/5092400/beats-53-89-of-users-with-c/
 *
 */