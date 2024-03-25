#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums) {
        int len = nums.size() + 1;
        int a[len];
        for (auto &it:a)it = 0;
        for (auto &it:nums)a[it]++;
        vector<int> ans;
        for (int i = 1; i < len; ++i) if (a[i] == 2)ans.emplace_back(i);
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
 * problem: https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
 * solution: https://leetcode.com/problems/find-all-duplicates-in-an-array/solutions/4921322/beats-98-64-of-users-with-c/
 *
 */