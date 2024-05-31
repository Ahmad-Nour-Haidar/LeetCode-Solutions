#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<int> singleNumber(vector<int> &nums) {
        int xorAll = 0;
        for (int &num : nums) xorAll ^= num;
        int rightmostSetBit = 1;
        while (!(xorAll & rightmostSetBit)) rightmostSetBit <<= 1;
        int num1 = 0, num2 = 0;
        for (int &num : nums) {
            if (num & rightmostSetBit) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }
        return {num1, num2};
    }
};

int main() {

    vector<int> v = {3, 5, 1, 2, 1, 2,};
    Solution().singleNumber(v);

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/single-number-iii/description/
 * solution: https://leetcode.com/problems/single-number-iii/solutions/5233576/beats-100-00-of-users-with-c/
 *
 */