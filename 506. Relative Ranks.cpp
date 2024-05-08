#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<string> findRelativeRanks(vector<int> &score) {
        string s[] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        priority_queue<pair<int, int>> pq;
        int n = score.size();
        for (int i = 0; i < n; ++i) {
            pq.emplace(make_pair(score[i], i));
        }
        int i = 0;
        vector<string> ans(n);
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            ans[it.second] = i < 3 ? s[i] : to_string(i + 1);
            i++;
        }
        return ans;
    }
};

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    Solution().findRelativeRanks(v);
    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n * log(n))
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/relative-ranks/description/
 * solution: https://leetcode.com/problems/relative-ranks/solutions/5128539/beats-96-69-of-users-with-c/
 *
 */