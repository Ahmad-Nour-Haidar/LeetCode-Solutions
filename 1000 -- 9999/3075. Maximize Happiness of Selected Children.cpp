#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    long long maximumHappinessSum(vector<int> &happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<>());
        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            ans += max(happiness[i] - i, 0);
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
 * Time Complexity: O(n * log(n))
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/maximize-happiness-of-selected-children/description/
 * solution: https://leetcode.com/problems/maximize-happiness-of-selected-children/solutions/5134513/beats-99-97-of-users-with-c/
 *
 */