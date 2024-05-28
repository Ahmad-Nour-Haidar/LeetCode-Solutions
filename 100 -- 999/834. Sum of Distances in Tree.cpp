#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> *graph{};
    int *subtree{}, totalDepth{}, nodes{};

    int dfs(int node, int prev, int depth) {
        totalDepth += depth;
        int total = 1;
        for (auto child:graph[node]) {
            if (child not_eq prev)
                total += dfs(child, node, depth + 1);
        }
        return subtree[node] = total;
    }

    void dfs2(int node, int prev, vector<int> &ans) {
        for (auto child:graph[node]) {
            if (child not_eq prev) {
                ans[child] = ans[node] - 2 * subtree[child] + nodes;
                dfs2(child, node, ans);
            }
        }
    }


public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
        nodes = n;
        graph = new vector<int>[n];
        subtree = new int[n];
        for (auto it :edges) {
            graph[it[0]].emplace_back(it[1]);
            graph[it[1]].emplace_back(it[0]);
        }
        dfs(0, -1, 0);
        vector<int> ans(n);
        ans[0] = totalDepth;
        dfs2(0, -1, ans);
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
 * problem: https://leetcode.com/problems/sum-of-distances-in-tree/description/
 * solution: https://leetcode.com/problems/sum-of-distances-in-tree/solutions/5084581/beats-97-41-of-users-with-c/
 *
 */