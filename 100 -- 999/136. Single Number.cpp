#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int ans = 0;
        for (auto it : nums) ans ^= it;
        return ans;
    }
};

int main() {

    vector<int> v = {4, 1, 2, 1, 2,};
    Solution().singleNumber(v);

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/single-number/description/
 * solution: https://leetcode.com/problems/single-number/submissions/1212133090/
 *
 */