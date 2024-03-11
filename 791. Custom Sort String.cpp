#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        int valueChar[130];
        for (int &i : valueChar)i = 100;
        int len = order.length();
        for (int i = 0; i < len; ++i) {
            valueChar[order[i]] = i;
        }
        sort(s.begin(), s.end(), [&valueChar](char const &char1, char const &char2) {
            return valueChar[char1] < valueChar[char2];
        });
        return s;
    }
};

int main() {

    cout << Solution().customSortString("abcd", "cba");

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n log(n))
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/custom-sort-string/description/
 * solution: https://leetcode.com/problems/custom-sort-string/solutions/4859081/beats-100-00-of-users-with-c-easy-easy-solution-with-explanation/
 *
 */