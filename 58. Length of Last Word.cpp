#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int lengthOfLastWord(string &s) {
        s = ' ' + s + ' ';
        int len = s.length(), l = -1, r = -1;;
        for (int i = len - 2; i > 0; --i) {
            if (s[i] not_eq ' ' and s[i + 1] == ' ')r = i;
            if (s[i] not_eq ' ' and s[i - 1] == ' ')l = i;
            if (l not_eq -1 and r not_eq -1)break;
        }
        return r - l + 1;
    }
};

int main() {

    string s = "   fly me   to   the moon  ";
    cout << Solution().lengthOfLastWord(s);

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/length-of-last-word/description/
 * solution: https://leetcode.com/problems/length-of-last-word/solutions/4955870/beats-100-00-of-users-with-c-0-ms/
 *
 */