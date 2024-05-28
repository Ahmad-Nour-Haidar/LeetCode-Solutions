#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
        int index = 0, len = nums.size();

        // find the minimum number
        if (nums[0] >= 0 and nums[len - 1] >= 0) {
            index = 0;
        } else if (nums[0] <= 0 and nums[len - 1] <= 0) {
            index = len - 1;
        } else {
            for (int i = 1; i < len; ++i) {
                if (nums[i] >= 0 and nums[i - 1] < 0) {
                    index = i - 1;
                    break;
                }
            }
        }
        // start solution
        vector<int> ans;
        int l = index, r = index + 1;
        while (l >= 0 or r < len) {
            if (l >= 0 and r < len) {
                if (abs(nums[l]) <= abs(nums[r])) {
                    ans.emplace_back((nums[l] * nums[l]));
                    l--;
                } else {
                    ans.emplace_back((nums[r] * nums[r]));
                    r++;
                }
            } else if (l >= 0) {
                ans.emplace_back((nums[l] * nums[l]));
                l--;
            } else if (r < len) {
                ans.emplace_back((nums[r] * nums[r]));
                r++;
            } else {
                break;
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
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/squares-of-a-sorted-array/description/
 * solution: https://leetcode.com/problems/squares-of-a-sorted-array/submissions/1191159982/
 *
 */