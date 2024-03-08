#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int> &hours, int target) {
        int ans = 0;
        for (auto it:hours) {
            ans += (it >= target);
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
 * problem: https://leetcode.com/problems/number-of-employees-who-met-the-target/description/
 * solution: https://leetcode.com/problems/number-of-employees-who-met-the-target/solutions/4840923/beats-100-00-of-users-with-c-easy/
 *
 */