#include <bits/stdc++.h>

using namespace std;


class Solution {
private:
    struct Node {
        int weight;
        int distance;
        int city;

        Node(int w, int d, int c) : weight(w), distance(d), city(c) {}

        bool operator<(const Node &other) const {
            if (distance not_eq other.distance)
                return distance > other.distance;
            return weight > other.weight;
        }
    };

public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {

        vector<pair<int, int>> adj[n + 1];
        for (auto it:flights) {
            adj[it[0]].emplace_back(make_pair(it[1], it[2]));
        }

        if (adj[src].empty())return -1;


        priority_queue<Node> pq;
        int wit[n + 1];
        for (int i = 0; i <= n; ++i) {
            wit[i] = INT_MAX;
        }
        pq.emplace(Node(0, -1, src));
        int ans = -1;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int newK = top.distance + 1;

            if (newK > k)continue;

            for (auto child :adj[top.city]) {
                int to = child.first;
                int wight = child.second;
                if (top.weight + wight < wit[to]) {
                    wit[to] = top.weight + wight;
                    pq.emplace(Node(top.weight + wight, newK, to));
                    if (to == dst)ans = top.weight + wight;
                }
            }
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
 * Time Complexity: O(n * log(n) )
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
 * solution: https://leetcode.com/problems/cheapest-flights-within-k-stops/submissions/1184138944/
 *
 */