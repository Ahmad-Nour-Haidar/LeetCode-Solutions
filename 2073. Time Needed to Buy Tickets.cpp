#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int timeRequiredToBuy(vector<int> &tickets, int k) {
        int len = tickets.size(), ans = 0;
        for (int i = 0; i < len; ++i) {
            ans += min(tickets[i], tickets[k]);
        }
        for (int i = len - 1; i > k; --i) {
            ans -= (tickets[i] >= tickets[k]);
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
 * problem: https://leetcode.com/problems/time-needed-to-buy-tickets/description/
 * solution: https://leetcode.com/problems/time-needed-to-buy-tickets/solutions/4995680/beats-100-00-of-users-with-c-easy-solution/
 *
 */