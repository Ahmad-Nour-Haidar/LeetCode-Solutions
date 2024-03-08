#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> bookedRoom;
        set<int> availableRoom;
        for (auto it:meetings) {
            pq.emplace(it[0], it[1]);
        }
        int cnt[n];
        for (int i = 0; i < n; ++i) {
            cnt[i] = 0;
            availableRoom.emplace(i);
        }

        while (!pq.empty()) {
            auto currentMeet = pq.top();
            pq.pop();
            long long start = currentMeet.first;
            long long end = currentMeet.second;
            while (!bookedRoom.empty() and start >= bookedRoom.top().first) {
                auto top = bookedRoom.top();
                bookedRoom.pop();
                availableRoom.emplace(top.second);
            }
            int availableIndexRoom;
            if (availableRoom.empty()) {
                auto top = bookedRoom.top();
                bookedRoom.pop();
                end = top.first + (end - start);
                availableIndexRoom = top.second;
            } else {
                availableIndexRoom = *availableRoom.begin();
            }
            availableRoom.erase(availableIndexRoom);
            bookedRoom.emplace(end, availableIndexRoom);
            cnt[availableIndexRoom]++;
        }

        int ans = 0, mx = 0;
        for (int i = 0; i < n; ++i) {
            if (mx < cnt[i]) {
                mx = cnt[i];
                ans = i;
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
 * Time Complexity: O(n log(n) )
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/meeting-rooms-iii/description/
 * solution: https://leetcode.com/problems/meeting-rooms-iii/submissions/1180142627/
 *
 */