#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, m;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool canMove(const int &i, const int &j) const {
        return i >= 0 and j >= 0 and i < n and j < m;
    }

    bool dfs(vector<vector<char>> &board, int i, int j, const string &word, bool **vis, string currentWord) {
        if (currentWord.length() > word.length()) return false;
        currentWord += board[i][j];
        if (currentWord == word)return true;
        vis[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (canMove(x, y) and !vis[x][y]) {
                int len = currentWord.length();
                if (board[x][y] == word[len]) {
                    if (dfs(board, x, y, word, vis, currentWord)) {
                        return true;
                    }
                }
            }
        }
        vis[i][j] = false;
        return false;
    }

    void init(bool **&vis) const {
        for (int i = 0; i < n; ++i) {
            vis[i] = new bool[m];
            for (int j = 0; j < m; ++j) {
                vis[i][j] = false;
            }
        }
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    bool exist(vector<vector<char>> &board, const string &word) {
        n = board.size();
        m = board[0].size();
        bool **vis = new bool *[n];
        init(vis);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, i, j, word, vis, "")) {
                        return true;
                    }
                }
            }
        }
        return false;
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
 * problem: https://leetcode.com/problems/word-search/description/
 * solution: https://leetcode.com/problems/word-search/submissions/1222243757/
 *
 */