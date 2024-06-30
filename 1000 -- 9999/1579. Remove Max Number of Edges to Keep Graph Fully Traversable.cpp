#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    class DisjointSet {
    private:
        int *size, *parent, n, components;

        void initial() {
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

    public:
        explicit DisjointSet(int n) {
            const int len = n + 1;
            size = new int[len];
            parent = new int[len];
            this->n = len;
            components = n;
            initial();
        }

        int find_set(int v) {
            if (v == parent[v])
                return v;
            return parent[v] = find_set(parent[v]);
        }

        // we attach the tree with the lower rank to the one with the bigger rank. rank = size
        bool union_sets(int a, int b) {
            a = find_set(a);
            b = find_set(b);
            if (a == b) return false;
            components--;
            if (size[a] > size[b]) {
                parent[b] = a;
                size[a] += size[b];
            } else {
                parent[a] = b;
                size[b] += size[a];
            }
            return true;
        }

        bool allConnected() const { return components == 1; }
    };

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int maxNumEdgesToRemove(const int &n, vector<vector<int>> &edges) {
        DisjointSet alice(n), bob(n);
        int edgesRequired = 0;
        for (const auto &it : edges) {
            if (it[0] == 3) {
                if (alice.union_sets(it[1], it[2]) | bob.union_sets(it[1], it[2])) {
                    edgesRequired++;
                }
            }
        }
        for (const auto &it : edges) {
            if (it[0] == 2) {
                if (bob.union_sets(it[1], it[2])) {
                    edgesRequired++;
                }
            } else if (it[0] == 1) {
                if (alice.union_sets(it[1], it[2])) {
                    edgesRequired++;
                }
            }
        }
        if (alice.allConnected() && bob.allConnected()) {
            return edges.size() - edgesRequired;
        }
        return -1;
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
 * problem: https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/
 * solution: https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/solutions/5389876/beats-9982/
 *
 */