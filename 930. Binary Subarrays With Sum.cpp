#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static int calc(vector<int> &nums, int goal) {
        if (goal < 0)return 0;
        int len = nums.size(), ans = 0, s = 0, l = 0, r = 0;
        while (r < len) {
            s += nums[r];
            while (s > goal) {
                s -= nums[l];
                l++;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }

public:
    int numSubarraysWithSum(vector<int> &nums, int goal) {
        return calc(nums, goal) - calc(nums, goal - 1);
    }
};

int main() {

    vector<int> v = {1, 0, 1, 0, 1};
    cout << Solution().numSubarraysWithSum(v, 2);
    cout << endl;
    cout << Solution().numSubarraysWithSum(v, 1);

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/binary-subarrays-with-sum/description/
 * solution: https://leetcode.com/problems/binary-subarrays-with-sum/solutions/4876313/beats-94-16-of-users-with-c/
 *
 */