#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    struct Fraction {
        double value;
        int x, y, index;

        Fraction(int x, int y, int index) : x(x), y(y), index(index) {
            this->value = (double) x / y;
        }

        bool operator<(const Fraction &other) const {
            return other.value < value;
        }
    };

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
        int n = arr.size();
        priority_queue<Fraction> pq;
        for (int i = 0; i < n; ++i) {
            pq.emplace(Fraction(arr[0], arr[i], 0));
        }
        while (k--) {
            auto top = pq.top();
            pq.pop();
            if (!k) {
                return {top.x, top.y};
            }
            int newIndex = top.index + 1;
            if (newIndex < n) {
                pq.emplace(Fraction(arr[newIndex], top.y, newIndex));
            }
        }
        return {};
    }
};

int main() {

    vector<int> v = {1, 2, 3, 5};
    Solution().kthSmallestPrimeFraction(v, 3);

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n * log(n))
 * Space Complexity: O(n)+
 *
 * problem: https://leetcode.com/problems/k-th-smallest-prime-fraction/description/
 * solution: https://leetcode.com/problems/k-th-smallest-prime-fraction/solutions/5138604/follow-up-complexity-n-log-n/
 *
 */