#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        int ans = 0, s = 0, len = nums.size();
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < len; ++i) {
            s += (nums[i] == 1 ? 1 : -1);
            if (m.count(s))ans = max(ans, i - m[s]);
            else m[s] = i;
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
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/contiguous-array/description/
 * solution: https://leetcode.com/problems/contiguous-array/solutions/4882502/beats-84-01-of-users-with-c/
 *
 */