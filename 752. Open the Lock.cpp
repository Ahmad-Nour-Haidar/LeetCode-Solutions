#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int getIndex(const string &value) {
        int ans = 0;
        int x = 1000;
        for (auto it:value) {
            ans += (it - '0') * x;
            x /= 10;
        }
        return ans;
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int openLock(vector<string> &deadends, const string &target) {
        bool vis[10000] = {};
        for (const auto &it:deadends)vis[getIndex(it)] = true;
        if (vis[0])return -1;
        queue<pair<string, int>> q;
        q.emplace(make_pair("0000", 0));
        vis[0] = true;
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            string s = current.first;
            int move = current.second;
            if (s == target) return move;
            for (int i = 0; i < 4; i++) {
                for (int j : {-1, 1}) {
                    int newDigit = (s[i] - '0' + j + 10) % 10;
                    string ss = s;
                    ss[i] = '0' + newDigit;
                    if (ss == target)return move + 1;
                    if (!vis[getIndex(ss)]) {
                        q.emplace(make_pair(ss, move + 1));
                        vis[getIndex(ss)] = true;
                    }
                }
            }
        }
        return -1;
    }
};

int main() {

    vector<string> v = {"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"};
    string target = "8888";
    Solution().openLock(v, target);

    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(E + V)
 * Space Complexity: O(E + V)
 *
 * problem: https://leetcode.com/problems/find-if-path-exists-in-graph/description/
 * solution: https://leetcode.com/problems/find-if-path-exists-in-graph/solutions/5055386/beats-80-84-of-users-with-c/
 *
 */