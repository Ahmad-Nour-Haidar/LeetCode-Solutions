#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker) {
        sort(worker.begin(), worker.end());
        priority_queue<pair<int, int>> pq;
        const int n = difficulty.size();
        for (int i = 0; i < n; ++i) {
            pq.emplace(profit[i], -difficulty[i]);
        }
        int ans = 0;
        int i = worker.size() - 1;
        while (!pq.empty() and i >= 0) {
            auto job = pq.top();
            if (worker[i] >= -job.second) {
                ans += job.first;
                i--;
            } else {
                pq.pop();
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
 * Time Complexity: O(n * log(n))
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/sum-of-square-numbers/description/
 * solution: https://leetcode.com/problems/most-profit-assigning-work/solutions/5331121/beats-97-94/
 *
 */