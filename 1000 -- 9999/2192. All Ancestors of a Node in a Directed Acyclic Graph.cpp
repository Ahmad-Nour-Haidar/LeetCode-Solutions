#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void dfs(vector<int> *graph, int parent, int current, vector<vector<int>> &res, bool *visit) {
        visit[current] = true;
        for (const auto &child : graph[current]) {
            if (!visit[child]) {
                res[child].emplace_back(parent);
                dfs(graph, parent, child, res, visit);
            }
        }
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<vector<int>> getAncestors(const int &n, vector<vector<int>> &edges) {
        vector<vector<int>> ans(n);
        vector<int> graph[n];
        for (const auto &it : edges) graph[it[0]].emplace_back(it[1]);
        bool visit[n];
        for (int i = 0; i < n; ++i) {
            for (auto &it:visit) it = false;
            dfs(graph, i, i, ans, visit);
        }
        for (int i = 0; i < n; ++i) sort(ans[i].begin(), ans[i].end());
        return ans;
    }
};

int main() {
    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n *  min(2000, n * (n - 1) / 2))
 * Space Complexity: O(n * m)
 *
 * problem: https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/
 * solution: https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/solutions/5386254/beats-96-60
 *
 */