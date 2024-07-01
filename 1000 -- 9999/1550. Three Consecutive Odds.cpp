#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    bool threeConsecutiveOdds(vector<int> &arr) {
        bool ans = false;
        const int n = arr.size() - 3;
        for (int i = 0; i <= n and !ans; ++i) {
            ans = (arr[i] & 1) and (arr[i + 1] & 1) and (arr[i + 2] & 1);
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
 * problem: https://leetcode.com/problems/three-consecutive-odds/description/
 * solution: https://leetcode.com/problems/three-consecutive-odds/solutions/5395140/beats-100-00
 *
 */