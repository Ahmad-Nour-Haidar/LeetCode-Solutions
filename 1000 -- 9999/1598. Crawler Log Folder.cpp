#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int minOperations(const vector<string> &logs) {
        int ans = 0;
        for (const auto &it:logs) {
            if (it == "../") {
                ans--;
                ans = max(ans, 0);
            } else if (it not_eq "./") ans++;
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
 * problem: https://leetcode.com/problems/crawler-log-folder/description/
 * solution: https://leetcode.com/problems/crawler-log-folder/solutions/5451619/beats-100-00-space-complexity-o-1
 *
 */