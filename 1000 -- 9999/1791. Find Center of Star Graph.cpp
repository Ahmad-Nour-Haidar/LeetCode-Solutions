#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int findCenter(vector<vector<int>> &edges) {
        int a[(int) 1e5 + 1];
        for (int &i:a) i = 0;
        int n = 0;
        for (auto &it : edges) {
            n += a[it[0]] == 0;
            n += a[it[1]] == 0;
            a[it[0]]++;
            a[it[1]]++;
        }
        for (int i = 1; i <= n; ++i) {
            if (a[i] == n - 1)return i;
        }
        return 0;
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
 * problem: https://leetcode.com/problems/find-center-of-star-graph/description/
 * solution: https://leetcode.com/problems/height-checker/solutions/5287585/beats-100-00-of-users-with-c/
 *
 */