#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int compareVersion(const string &version1, const string &version2) {
        int v1 = 0, v2 = 0, n1 = version1.length(), n2 = version2.length();
        for (int i = 0, j = 0; i < n1 or j < n2; i++, j++) {
            while (i < n1 and version1[i] != '.') {
                v1 = v1 * 10 + (version1[i] - '0');
                i++;
            }
            while (j < n2 and version2[j] != '.') {
                v2 = v2 * 10 + (version2[j] - '0');
                j++;
            }
            if (v1 not_eq v2) return v1 < v2 ? -1 : 1;
            v1 = 0;
            v2 = 0;
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
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/compare-version-numbers/description/
 * solution: https://leetcode.com/problems/compare-version-numbers/solutions/5104360/beats-100-00-of-users-with-c/
 *
 */