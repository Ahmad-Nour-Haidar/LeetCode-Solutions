#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int numRescueBoats(vector<int> &people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1, ans = 0;
        while (l <= r) {
            ans++;
            if (l == r) break;
            if (r > 0 and (people[r] + people[r - 1]) <= limit) r -= 2;
            else if ((people[r] + people[l]) <= limit) r--, l++;
            else r--;
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
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/boats-to-save-people/description/
 * solution: https://leetcode.com/problems/boats-to-save-people/solutions/5109038/beats-98-90-of-users-with-c/
 *
 */