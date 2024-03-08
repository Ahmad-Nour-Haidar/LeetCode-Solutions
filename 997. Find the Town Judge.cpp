#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>> &trust) {
        bool isInLeft[(n + 1)];
        int cnt[(n + 1)];
        for (int i = 0; i <= n; ++i) {
            isInLeft[i] = false;
            cnt[i] = 0;
        }
        for (auto it:trust) {
            isInLeft[it[0]] = true;
            cnt[it[1]]++;
        }
        int ans = -1;
        for (int i = 1; i <= n; ++i) {
            if (!isInLeft[i] and cnt[i] == n - 1) {
                ans = i;
                break;
            }
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
 * problem: https://leetcode.com/problems/find-the-town-judge/description/
 * solution: https://leetcode.com/problems/find-the-town-judge/submissions/1182668735/
 *
 */