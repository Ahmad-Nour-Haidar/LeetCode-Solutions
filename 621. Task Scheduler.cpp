#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {
        int c[26] = {}; // all zeros
        for (auto it:tasks)c[it - 'A']++;
        int mx = 0;
        for (auto it:c)mx = max(mx, it);
        int last = 0;
        for (auto it:c)last += (it == mx);
        int ans = max((n + 1) * (mx - 1) + last, (int) tasks.size());
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
 * problem: https://leetcode.com/problems/task-scheduler/description/
 * solution: https://leetcode.com/problems/task-scheduler/solutions/4897445/beats-98-07-of-users-with-c-space-complexity-o-1/
 *
 */