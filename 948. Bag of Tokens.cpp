#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int> &tokens, int power) {
        int len = tokens.size();
        if (len == 1)return power >= tokens[0];
        sort(tokens.begin(), tokens.end());
        int score = 0, ans = 0;
        int l = 0, r = len - 1;
        while (l <= r) {
            if (power >= tokens[l] and tokens[l] not_eq -1) {
                power -= tokens[l];
                tokens[l] = -1;
                score++;
                l++;
                ans = max(ans, score);
            } else if (score > 0 and tokens[r] not_eq -1) {
                power += tokens[r];
                tokens[r] = -1;
                r--;
                ans = max(ans, score);
                score--;
            } else {
                break;
            }
        }
        ans = max(ans, score);
        return ans;
    }
};

int main() {

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n * log (n) )
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/bag-of-tokens/description/
 * solution: https://leetcode.com/problems/bag-of-tokens/solutions/4840783/beats-100-00-of-users-with-c-easy/
 *
 */