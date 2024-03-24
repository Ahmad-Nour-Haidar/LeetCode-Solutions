#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums) {
        int len = nums.size();
        int a[len + 1];
        for (int &i:a)i = 0;
        for (auto it:nums)a[it]++;
        vector<int> ans(2);
        for (int i = 1; i <= len; ++i) {
            if (a[i] == 0)ans[1] = i;
            if (a[i] == 2)ans[0] = i;
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
 * problem: https://leetcode.com/problems/set-mismatch/description/
 * solution: https://leetcode.com/problems/set-mismatch/submissions/1212146402/
 *
 */