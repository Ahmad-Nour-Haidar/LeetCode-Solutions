#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    void sortColors(vector<int> &nums) {
        int l = 0, mid = 0, r = nums.size() - 1;
        while (mid <= r) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[l]);
                l++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[r]);
                r--;
            }
        }
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
 * problem: https://leetcode.com/problems/sort-colors/description/
 * solution: https://leetcode.com/problems/sort-colors/solutions/4977957/beats-100-00-of-users-with-c-one-pass/
 *
 */