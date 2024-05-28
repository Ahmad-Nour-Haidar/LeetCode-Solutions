#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    struct Help {
        int dist, x, y;

        Help(int dist, int x, int y) : dist(dist), x(x), y(y) {}

        bool operator<(const Help &other) const {
            if (other.dist not_eq dist)return other.dist < dist;
            if (other.x not_eq x)return other.x < x;
            return other.y < y;
        }
        bool operator>(const Help &other) const {
            if (other.dist not_eq dist)return other.dist > dist;
            if (other.x not_eq x)return other.x > x;
            return other.y > y;
        }
    };

    int n{};
    int dir[5] = {0, 1, 0, -1, 0};
    int **dist = {};
    bool **vis = {};

    void initial() {
        dist = new int *[n];
        vis = new bool *[n];
        for (int i = 0; i < n; ++i) {
            dist[i] = new int[n];
            vis[i] = new bool[n];
            for (int j = 0; j < n; ++j) {
                dist[i][j] = INT_MAX - 20000;
                vis[i][j] = false;
            }
        }
    }

    bool canMove(int i, int j) {
        return i >= 0 and i < n and j >= 0 and j < n;
    }

    void bfs(vector<vector<int>> &grid) {
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    dist[i][j] = 0;
                    q.emplace(make_pair(i, j));
                }
            }
        }
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int i = front.first;
            int j = front.second;
            int distance = dist[i][j];
            for (int k = 0; k < 4; ++k) {
                int r = i + dir[k];
                int c = j + dir[k + 1];
                if (canMove(r, c) and dist[r][c] > distance + 1) {
                    dist[r][c] = distance + 1;
                    q.emplace(make_pair(r, c));
                }
            }
        }
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int maximumSafenessFactor(vector<vector<int>> &grid) {
        n = grid.size();
        if (grid[0][0] or grid[n - 1][n - 1]) return 0;
        initial();
        bfs(grid);
        priority_queue<Help, vector<Help>, greater<>> pq;
        pq.emplace(Help(dist[0][0], 0, 0));
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            if (top.x == n - 1 and top.y == n - 1)return top.dist;
            for (int k = 0; k < 4; ++k) {
                int r = top.x + dir[k];
                int c = top.y + dir[k + 1];
                if (canMove(r, c) and !vis[r][c]) {
                    int d = min(top.dist, dist[r][c]);
                    pq.emplace(Help{d, r, c});
                    vis[r][c] = true;
                }
            }
        }
        return 0;
    }
};

int main() {

    vector<vector<int>> v = {
            {0, 0, 1},
            {0, 0, 0},
            {0, 0, 0},
    };

    cout << Solution().maximumSafenessFactor(v);

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n^2 * log(n))
 * Space Complexity: O(n^2)
 *
 * problem: https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/
 * solution: https://leetcode.com/problems/find-the-safest-path-in-a-grid/solutions/5161875/beats-100-00-of-users-with-c/
 *
 */