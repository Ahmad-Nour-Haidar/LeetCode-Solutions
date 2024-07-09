#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    double averageWaitingTime(vector<vector<int>> &customers) {
        int currentTime = 0;
        double ans = 0;
        for (const auto &it:customers) {
            currentTime = max(currentTime, it[0]);
            currentTime += it[1];
            ans += currentTime - it[0];
        }
        return ans / customers.size();
    }
};

int main() {

    vector<vector<int>> v = {{1, 2},
                             {2, 5},
                             {4, 3}};

    Solution().averageWaitingTime(v);
    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/average-waiting-time/description/
 * solution: https://leetcode.com/problems/average-waiting-time/solutions/5444990/beats-99-71
 *
 */