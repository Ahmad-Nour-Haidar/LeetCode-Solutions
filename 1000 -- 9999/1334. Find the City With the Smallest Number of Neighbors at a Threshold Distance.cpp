#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
        int dist[n][n];
        // Initialize the distance matrix
        for (auto &it:dist) {
            for (auto &i:it)i = INT_MAX;
        }
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }
        for (const auto &edge : edges) {
            int from = edge[0], to = edge[1], weight = edge[2];
            dist[from][to] = weight;
            dist[to][from] = weight;
        }

        // Apply Floyd-Warshall algorithm
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Find the city with the smallest number of neighbors within the threshold
        int minCount = INT_MAX;
        int resultCity = -1;
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (count < minCount || (count == minCount && i > resultCity)) {
                minCount = count;
                resultCity = i;
            }
        }

        return resultCity;
    }
};

int main() {
    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n^3)
 * Space Complexity: O(n^2)
 *
 * problem: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
 * solution: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/solutions/5537135/beats-99-73
 *
 */