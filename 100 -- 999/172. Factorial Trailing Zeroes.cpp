#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static pair<int, int> calc_2_5(int n) {
        pair<int, int> ans;
        while (n % 2 == 0) {
            ans.first++;
            n /= 2;
        }
        while (n % 5 == 0) {
            ans.second++;
            n /= 5;
        }
        return ans;
    }

public:
    int trailingZeroes(int n) {
        int _2 = 0;
        int _5 = 0;
        for (int i = 2; i <= n; i++) {
            auto a = calc_2_5(i);
            _2 += a.first;
            _5 += a.second;
        }
        return min(_2, _5);
    }

    int trailingZeroes2(int n) {
        int count = 0;
        for (int i = 5; n / i >= 1; i *= 5)
            count += n / i;
        return count;
    }
};

int main() {


    cout << Solution().trailingZeroes(5);


    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * problem: https://leetcode.com/problems/factorial-trailing-zeroes/description/
 *
 * Time Complexity: O(n * log(n))
 * Space Complexity: O(1)
 * solution: https://leetcode.com/problems/factorial-trailing-zeroes/submissions/1197645282/
 *
 * Time Complexity: O(log5(n))
 * Space Complexity: O(1)
 * solution: https://leetcode.com/problems/factorial-trailing-zeroes/submissions/1197647288/
 *
 */