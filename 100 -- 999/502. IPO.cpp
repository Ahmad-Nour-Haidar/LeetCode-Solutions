#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int findMaximizedCapital(const int &k, int &w, const vector<int> &profits, const vector<int> &capital) {
        int n = profits.size();
        vector<pair<int, int>> works;
        for (int i = 0; i < n; ++i) {
            works.emplace_back(capital[i], profits[i]);
        }
        sort(works.begin(), works.end());
        priority_queue<int> pq;
        int i = 0;
        for (int j = 0; j < k; ++j) {
            while (i < n && works[i].first <= w) {
                pq.emplace(works[i].second);
                i++;
            }
            if (pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
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
 * problem: https://leetcode.com/problems/ipo/description/
 * solution: https://leetcode.com/problems/ipo/solutions/5316641/beats-99-32-c/
 *
 */