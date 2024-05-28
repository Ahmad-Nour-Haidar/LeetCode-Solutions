#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    string reversePrefix(string &word, const char &ch) {
        reverse(word.begin(), word.begin() + word.find_first_of(ch) + 1);
        return word;
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
 * problem: https://leetcode.com/problems/reverse-prefix-of-word/description/
 * solution: https://leetcode.com/problems/reverse-prefix-of-word/solutions/5094271/beats-100-00-of-users-with-c/
 *
 */