#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int passThePillow(const int &n, const int &time) {
        const int n_1 = n - 1;
        const int tour = time / n_1;
        const int r = time % n_1;
        return (tour & 1) ? n - r : 1 + r;
    }
};

int main() {
    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/pass-the-pillow/description/
 * solution: https://leetcode.com/problems/pass-the-pillow/solutions/5425003/beats-100-00-time-complexity-o-1-space-complexity-o-1
 *
 */