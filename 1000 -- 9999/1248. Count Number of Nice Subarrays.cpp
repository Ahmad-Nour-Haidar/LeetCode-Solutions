#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int help(vector<int> &nums, const int &k) {
        if (k < 0)return 0;
        int n = nums.size(), result = 0, index = 0, odd = 0;
        for (int i = 0; i < n; ++i) {
            odd += (nums[i] & 1);
            while (odd > k) {
                odd -= (nums[index] & 1);
                index++;
            }
            result += (i - index + 1);
        }
        return result;
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int numberOfSubarrays(vector<int> &nums, const int &k) {
        return help(nums, k) - help(nums, k - 1);
    }
};

int main() {

    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/count-number-of-nice-subarrays/description/
 * solution: https://leetcode.com/problems/count-number-of-nice-subarrays/solutions/5352648/beats-99-97/
 *
 */