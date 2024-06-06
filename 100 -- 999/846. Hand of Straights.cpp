#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    bool isNStraightHand(const vector<int> &hand, const int &groupSize) {
        if (hand.size() % groupSize not_eq 0) return false;
        map<int, int> m;
        for (auto &it:hand) m[it]++;
        while (m.size()) {
            int mn = m.begin()->first;
            for (int i = mn; i < mn + groupSize; ++i) {
                if (!m.count(i))return false;
                m[i]--;
                if (!m[i]) m.erase(i);
            }
        }
        return true;
    }
};

int main() {

    vector<int> v = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    Solution().isNStraightHand(v, 3);

    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/hand-of-straights/description/
 * solution: https://leetcode.com/problems/hand-of-straights/solutions/5269036/beats-85-80-of-users-with-c/
 *
 */