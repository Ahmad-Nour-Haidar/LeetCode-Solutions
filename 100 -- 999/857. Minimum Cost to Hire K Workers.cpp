#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = {(double) wage[i] / quality[i], quality[i]};
        }
        sort(v.begin(), v.end());
        priority_queue<int> pq;
        double ans = INT_MAX;
        double sum = 0;
        for (int i = 0; i < n; ++i) {
            pq.emplace(v[i].second);
            sum += v[i].second;
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                ans = min(ans, sum * v[i].first);
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
 * problem: https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/
 * solution: https://leetcode.com/problems/minimum-cost-to-hire-k-workers/solutions/5143203/beats-100-00-of-users-with-c/
 *
 */