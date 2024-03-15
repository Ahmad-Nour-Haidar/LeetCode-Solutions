#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int len = nums.size();
        vector<int> ans(len);
        int x = 1;
        for (int i = 0; i < len; ++i) {
            ans[i] = x;
            x *= nums[i];
        }
        x = 1;
        for (int i = len - 1; i >= 0; --i) {
            ans[i] *= x;
            x *= nums[i];
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
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/product-of-array-except-self/description/
 * solution: https://leetcode.com/problems/product-of-array-except-self/solutions/4878022/beats-90-04-of-users-with-c-o-n-time-o-1-space-easy-solution/
 *
 */