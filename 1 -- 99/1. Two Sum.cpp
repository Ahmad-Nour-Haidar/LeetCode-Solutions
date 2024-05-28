#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> m;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (m.find(target - nums[i]) not_eq m.end()) {
                return {i, m[target - nums[i]]};
            }
            m[nums[i]] = i;
        }
        return {};
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
 * problem: https://leetcode.com/problems/two-sum/description/
 * solution: https://leetcode.com/problems/two-sum/submissions/931865004/
 *
 */