#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    typedef long long ll;
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    ll maximumImportance(int n, vector<vector<int>> &roads) {
        int importance[n];
        for (auto &it:importance) it = 0;
        for (const auto &it : roads) {
            importance[it[0]]++;
            importance[it[1]]++;
        }
        int cities[n];
        for (int i = 0; i < n; i++) cities[i] = i;
        sort(cities, cities + n, [&](const int &a, const int &b) {
            return importance[a] > importance[b];
        });
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (ll) (n - i) * importance[cities[i]];
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
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/maximum-total-importance-of-roads/description/
 * solution: https://leetcode.com/problems/height-checker/solutions/5287585/beats-100-00-of-users-with-c/
 *
 */