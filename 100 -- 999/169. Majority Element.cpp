#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = nums[0];
        int c = 1;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                c++;
            } else {
                if (c > n / 2)ans = nums[i];
                c = 1;
            }
        }
        if (c > n / 2)ans = nums[n - 1];
        return ans;
    }
};

int main() {

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n * log(n))
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/majority-element/description/
 * solution: https://leetcode.com/problems/majority-element/submissions/1172966036/
 *
 */