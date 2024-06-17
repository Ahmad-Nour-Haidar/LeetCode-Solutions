#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    bool judgeSquareSum(int n) {
        for (int i = 2; i * i <= n; ++i) {
            int count = 0;
            if (n % i == 0) {
                while (n % i == 0) {
                    count++;
                    n /= i;
                }
                if (i % 4 == 3 && count & 1) return false;
            }
        }
        return n % 4 not_eq 3;
    }
};

int main() {

    cout << Solution().judgeSquareSum(17);

    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(sqrt(n))
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/sum-of-square-numbers/description/
 * solution: https://leetcode.com/problems/sum-of-square-numbers/solutions/5325830/beats-100-00/i
 *
 */