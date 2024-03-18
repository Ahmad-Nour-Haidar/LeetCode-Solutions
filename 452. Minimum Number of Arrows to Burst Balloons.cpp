#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        int len = points.size();
        sort(points.begin(), points.end());
        int ans = 0, e = points[0][1];
        for (int i = 0; i < len; ++i) {
            if (points[i][0] > e) {
                ans++;
                e = points[i][1];
            } else {
                e = min(e, points[i][1]);
            }
        }
        ans++;
        return ans;
    }
};

int main() {

    vector<vector<int>> v = {
            {31176229, 84553602},
            {59484421, 74029340},
            {8413784,  65312321},
            {34575198, 108169522},
            {49798315, 88462685},
            {29566413, 114369939},
            {12776091, 37045071},
            {11759956, 61001829},
            {37806862, 80806032},
            {82906996, 118404277}
    };

    cout << Solution().findMinArrowShots(v);

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n * log(n))
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
 * solution: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/solutions/4890748/beats-92-79-of-users-with-c/
 *
 */