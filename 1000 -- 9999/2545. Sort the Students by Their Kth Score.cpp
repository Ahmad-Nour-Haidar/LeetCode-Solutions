#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k) {
        sort(score.begin(), score.end(), [&k](vector<int> const &a, vector<int> const &b) {
            return a[k] > b[k];
        });
        return score;
    }
};

int main() {

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n log(n))
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/sort-the-students-by-their-kth-score/description/
 * solution: https://leetcode.com/problems/sort-the-students-by-their-kth-score/solutions/4861868/beats-99-03-of-users-with-c-solve-in-one-line/
 *
 */