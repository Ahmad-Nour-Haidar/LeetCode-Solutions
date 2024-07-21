#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> ans(k, vector<int>(k, 0));

        const auto rowOrder = topologicalSort(k, rowConditions);
        const auto colOrder = topologicalSort(k, colConditions);

        if (rowOrder.empty() or colOrder.empty()) {
            return {};
        }

        unordered_map<int, int> rowPosition, colPosition;
        for (int i = 0; i < k; ++i) {
            rowPosition[rowOrder[i]] = i;
            colPosition[colOrder[i]] = i;
        }

        for (int i = 1; i <= k; ++i) {
            ans[rowPosition[i]][colPosition[i]] = i;
        }

        return ans;
    }

private:
    vector<int> topologicalSort(int k, vector<vector<int>>& conditions) {
        vector<int> inDegree(k + 1, 0);
        unordered_map<int, vector<int>> graph;

        for (const auto& condition : conditions) {
            graph[condition[0]].emplace_back(condition[1]);
            ++inDegree[condition[1]];
        }

        queue<int> q;
        for (int i = 1; i <= k; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.emplace_back(node);

            for (int neighbor : graph[node]) {
                --inDegree[neighbor];
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (order.size() != k) {
            return {};
        }

        return order;
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
 * problem: https://leetcode.com/problems/build-a-matrix-with-conditions/description/
 * solution: https://leetcode.com/problems/build-a-matrix-with-conditions/solutions/5510178/beats-94-37
 *
 */