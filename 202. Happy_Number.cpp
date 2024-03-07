#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int sq;
        set<int> s;
        while (n) {
            sq = 0;
            while (n) {
                int m = n % 10;
                n /= 10;
                sq += (m * m);
            }
            n = sq;
            if (n == 1) return true;
            else if (s.count(n)) return false;
            s.emplace(n);
        }
        return false;
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
 * problem: https://leetcode.com/problems/happy-number/description/
 * solution: https://leetcode.com/problems/happy-number/submissions/1195766402/
 *
 */