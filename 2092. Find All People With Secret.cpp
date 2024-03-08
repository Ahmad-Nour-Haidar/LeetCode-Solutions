#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson) {
        vector<pair<int, int>> graph[n];
        for (auto it:meetings) {
            graph[it[0]].emplace_back(it[1], it[2]);
            graph[it[1]].emplace_back(it[0], it[2]);
        }
        bool vis[n];
        for (auto &i:vis)i = false;
        // {time, person}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, 0);
        pq.emplace(0, firstPerson);
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int currentTime = top.first;
            int currentPerson = top.second;
            if (vis[currentPerson])continue;
            vis[currentPerson] = true;
            for (auto it :graph[currentPerson]) {
                // it => {person, time}
                if (it.second >= currentTime) {
                    pq.emplace(it.second, it.first);
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (vis[i])ans.emplace_back(i);
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
 * Time Complexity: O(n+m)
 * Space Complexity: O(n+m)
 *
 * problem: https://leetcode.com/problems/find-all-people-with-secret/description/
 * solution: https://leetcode.com/problems/find-all-people-with-secret/submissions/1184849360/
 *
 */