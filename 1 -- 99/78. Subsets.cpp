#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;

    void help(vector<int> &nums, vector<int> &subset, int i = 0) {
        ans.emplace_back(subset);
        for (int j = i; j < nums.size(); ++j) {
            subset.emplace_back(nums[j]);
            help(nums, subset, j + 1);
            subset.pop_back();
        }
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        vector<int> subset;
        help(nums, subset, 0);
        return ans;
    }
};

int main() {

    vector<int> test = {1, 2, 3};
    Solution().subsets(test);

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(2 ^ n)
 * Space Complexity: O(2 ^ n)
 *
 * problem: https://leetcode.com/problems/subsets/description/
 * solution: https://leetcode.com/problems/subsets/solutions/5189840/beats-100-00-of-users-with-c/
 *
 */