#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int minMovesToSeat(vector<int> &seats, vector<int> &students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int ans = 0, n = seats.size();
        for (int i = 0; i < n; ++i) {
            ans += abs(seats[i] - students[i]);
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
 * Time Complexity: O(n * log(n))
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/description/
 * solution: https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/solutions/5307356/beats-100-00-of-users-with-c/
 *
 */