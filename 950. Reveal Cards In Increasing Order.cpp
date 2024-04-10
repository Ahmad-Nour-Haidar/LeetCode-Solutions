#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<int> deckRevealedIncreasing(vector<int> &deck) {
        sort(deck.begin(), deck.end());
        deque<int> dq;
        int len = deck.size();
        dq.emplace_front(deck[len - 1]);
        for (int i = len - 2; i >= 0; --i) {
            dq.emplace_front(dq.back());
            dq.pop_back();
            dq.emplace_front(deck[i]);
        }
        deck.clear();
        while (!dq.empty()) {
            deck.emplace_back(dq.front());
            dq.pop_front();
        }
        return deck;
    }
};

int main() {

    vector<int> v = {17, 13, 11, 2, 3, 5, 7};

    Solution().deckRevealedIncreasing(v);

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n log(n)) => sorting
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/reveal-cards-in-increasing-order/description/
 * solution: https://leetcode.com/problems/reveal-cards-in-increasing-order/submissions/1228574148/
 *
 */