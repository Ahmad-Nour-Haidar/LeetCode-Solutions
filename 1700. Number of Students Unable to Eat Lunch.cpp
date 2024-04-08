#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int countStudents(vector<int> &students, vector<int> &sandwiches) {
        int a[] = {0, 0};
        for (auto it : students)a[it]++;
        int len = sandwiches.size();
        for (auto it : sandwiches) {
            if (a[it] == 0) break;
            if (!len) break;
            a[it]--;
            len--;
        }
        return len;
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
 * problem: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/
 * solution: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/solutions/4991665/beats-100-00-of-users-with-c/
 *
 */