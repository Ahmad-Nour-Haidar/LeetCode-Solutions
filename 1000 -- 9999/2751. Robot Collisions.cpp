#include <bits/stdc++.h>

using namespace std;

class Solution {
    static bool canCollide(const int &a, const int &b, const string &s) {
        return s[a] == 'R' and s[b] == 'L';
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<int>
    survivedRobotsHealths(const vector<int> &positions, vector<int> &healths, const string &directions) {
        int n = positions.size();
        int robots[n];
        for (int i = 0; i < n; ++i) {
            robots[i] = i;
        }
        sort(robots, robots + n, [&](const int &a, const int &b) {
            return positions[a] < positions[b];
        });
        stack<int> st;
        for (const int &robot:robots) {
            if (st.empty()) {
                st.emplace(robot);
                continue;
            }
            while (!st.empty()) {
                int top = st.top();
                if (!canCollide(top, robot, directions)) {
                    st.emplace(robot);
                    break;
                }
                if (healths[top] == healths[robot]) {
                    st.pop();
                    healths[top] = 0;
                    healths[robot] = 0;
                    break;
                } else if (healths[top] < healths[robot]) {
                    st.pop();
                    healths[top] = 0;
                    healths[robot]--;
                } else {
                    healths[top]--;
                    healths[robot] = 0;
                    break;
                }
            }
        }
        vector<int> ans;
        for (const int &it:healths) {
            if (it > 0) {
                ans.emplace_back(it);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> positions = {3, 5, 2, 6};
    vector<int> healths = {10, 10, 15, 12};
    string directions = "RLRL";

    Solution().survivedRobotsHealths(positions, healths, directions);

    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n*log(n))
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/robot-collisions/description/
 * solution: https://leetcode.com/problems/robot-collisions/solutions/5469306/beats-100-00-runtime-beats-100-00-memory
 *
 */