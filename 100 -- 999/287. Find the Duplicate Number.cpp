#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        bool b[(int) nums.size()];
        for (bool &it:b)it = false;
        for (auto it:nums) {
            if (b[it])return it;
            b[it] = true;
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
 * problem: https://leetcode.com/problems/find-the-duplicate-number/description/
 * solution: https://leetcode.com/problems/find-the-duplicate-number/solutions/4916521/beats-98-51-of-users-with-c-time-o-n-space-o-n/
 *
 */