#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int findTheWinner(int n, int k) {
        int ans = 1;
        for (int i = 1; i <= n; ++i) {
            ans = (ans + k - 1) % i + 1;
        }
        return ans;
    }
};

int main() {

    Solution().findTheWinner(5, 2);

    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(log(numExchange))
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/
 * solution: https://leetcode.com/problems/find-the-winner-of-the-circular-game/solutions/5438570/beats-100-00
 *
 */