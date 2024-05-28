#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long largestPerimeter(vector<int> &nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        bool found = false;
        long long ans = 0;
        long long mx = 0;
        int c = 0;
        for (int i = 0; i < len - 1; ++i) {
            c++;
            mx += nums[i];
            if (mx > nums[i + 1] and c >= 2) {
                found = true;
                ans = mx;
                ans += nums[i + 1];
            }
        }
        if (!found) return -1;
        return ans;
    }
};

int main() {

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n log(n) )
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/
 * solution: https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/submissions/1176113370/
 *
 */