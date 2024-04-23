#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if (n == 1)return {0};
        int degree[n];
        for (auto &it:degree)it = 0;
        vector<int> graph[n];
        for (auto &it:edges) {
            graph[it[0]].emplace_back(it[1]);
            graph[it[1]].emplace_back(it[0]);
            degree[it[0]]++;
            degree[it[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) if (degree[i] == 1) q.emplace(i);
        while (n > 2) {
            int nodes = q.size();
            n -= nodes;
            for (int i = 0; i < nodes; ++i) {
                int front = q.front();
                q.pop();
                for (auto &it:graph[front]) {
                    degree[it]--;
                    if (degree[it] == 1) q.emplace(it);
                }
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.emplace_back(q.front());
            q.pop();
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
 * problem: https://leetcode.com/problems/minimum-height-trees/description/
 * solution: https://leetcode.com/problems/minimum-height-trees/solutions/5063411/beats-98-82-of-users-with-c/
 *
 */