#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
        priority_queue<int> pq;
        long long s = 0;
        int len = heights.size();
        int i = 1;
        for (; i < len; ++i) {
            if (heights[i - 1] < heights[i]) {
                long long d = heights[i] - heights[i - 1];
                pq.emplace(d);
                s += d;
                if (s > bricks and ladders == 0) {
                    i--;
                    break;
                }
                while (s > bricks and !pq.empty()) {
                    int top = pq.top();
                    pq.pop();
                    s -= top;
                    ladders--;
                    if (ladders == 0) {
                        break;
                    }
                }
            }
        }
        if (i >= len)i--;
        return i;
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
 * problem: https://leetcode.com/problems/furthest-building-you-can-reach/description/
 * solution: https://leetcode.com/problems/furthest-building-you-can-reach/submissions/1177545228/
 *
 */