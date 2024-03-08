#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int> &nums) {
        vector<int> positive, negative;
        for (auto it: nums)it > 0 ? positive.push_back(it) : negative.push_back(it);
        vector<int> ans;
        int len = positive.size();
        for (int i = 0; i < len; ++i) {
            ans.push_back(positive[i]);
            ans.push_back(negative[i]);
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
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
 * solution: https://leetcode.com/problems/rearrange-array-elements-by-sign/submissions/1175048710/
 *
 */