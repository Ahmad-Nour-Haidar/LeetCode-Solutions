#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int numWaterBottles(int numBottles, const int &numExchange) {
        int ans = numBottles;
        while (numBottles >= numExchange) {
            const int canConvert = numBottles / numExchange;
            const int r = numBottles % numExchange;
            ans += canConvert;
            numBottles /= numExchange;
            numBottles += r;
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
 * Time Complexity: O(log(numExchange))
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/water-bottles/description/
 * solution: https://leetcode.com/problems/water-bottles/solutions/5432672/beats-100-00
 *
 */