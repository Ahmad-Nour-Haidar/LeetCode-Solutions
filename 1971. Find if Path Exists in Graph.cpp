#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> *graph{};
    bool *vis{};

    bool dfs(int source, int destination) {
        if (source == destination)return true;
        vis[source] = true;
        for (auto it:graph[source]) {
            if (!vis[it]) {
                if (dfs(it, destination)) return true;
            }
        }
        return false;
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
        vis = new bool[n];
        for (int i = 0; i < n; ++i)vis[i] = false;
        /// build graph
        graph = new vector<int>[n]; // array of vectors
        for (auto it:edges) {
            graph[it[0]].emplace_back(it[1]);
            graph[it[1]].emplace_back(it[0]);
        }
        /// start solution
        return dfs(source, destination);
    }
};

int main() {

    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n * m)
 * Space Complexity: O(n * m)
 *
 * problem: https://leetcode.com/problems/find-if-path-exists-in-graph/description/
 * solution: https://leetcode.com/problems/find-if-path-exists-in-graph/solutions/5055386/beats-80-84-of-users-with-c/
 *
 */