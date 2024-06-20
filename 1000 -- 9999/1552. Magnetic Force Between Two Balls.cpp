#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool check(const vector<int> &position, int m, const int &value) {
        m--;
        int start = position[0];
        int n = position.size();
        for (int i = 1; i < n; ++i) {
            if (position[i] - start >= value) {
                m--;
                start = position[i];
            }
            if (!m) return true;
        }
        return false;
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int maxDistance(vector<int> &position, const int &m) {
        sort(position.begin(), position.end());
        int ans = 1;
        int l = 1, r = 1e9, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (check(position, m, mid)) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
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
 * Time Complexity: O(n * log(n))
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/magnetic-force-between-two-balls/description/
 * solution: https://leetcode.com/problems/magnetic-force-between-two-balls/solutions/5340149/beats-98-40/
 *
 */