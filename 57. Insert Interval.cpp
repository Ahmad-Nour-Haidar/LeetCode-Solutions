#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        int len = intervals.size();
        bool isInserted = false;
        vector<vector<int>> ans;
        for (int i = 0; i < len; ++i) {
            if (!isInserted and newInterval[0] <= intervals[i][1] and newInterval[1] >= intervals[i][0]) {
                int j = i + 1;
                while (j < len and newInterval[1] >= intervals[j][0]) j++;
                j--;
                vector<int> temp = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[j][1])};
                ans.emplace_back(temp);
                isInserted = true;
                i = j;
            } else {
                ans.emplace_back(intervals[i]);
            }
        }
        if (intervals.empty())ans.emplace_back(newInterval);
        else if (!isInserted) {
            if (newInterval[0] > ans[len - 1][1])ans.emplace_back(newInterval);
            else if (newInterval[1] < ans[0][0])ans.emplace(ans.begin(), newInterval);
            else {
                int index = lower_bound(intervals.begin(), intervals.end(), newInterval) - intervals.begin();
                ans.emplace(ans.begin() + index, newInterval);
            }
        }
        return ans;
    }
};

int main() {

    vector<vector<int>> v = {{3,  5},
                             {12, 15}};
    vector<int> vv = {6, 6};
    auto it = lower_bound(v.begin(), v.end(), vv);
    Solution().insert(v, vv);

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/insert-interval/description/
 * solution: https://leetcode.com/problems/insert-interval/solutions/4890642/beats-99-62-of-users-with-c/
 *
 */