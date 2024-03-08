#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> ss;
        int mx = 0;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            ss.clear();
            for (int j = i; j < 256 and j < len; ++j) {
                if (ss.count(s[j])) {
                    mx = max(mx, (int) ss.size());
                    ss.clear();
                }
                ss.emplace(s[j]);
            }
            mx = max(mx, (int) ss.size());
        }
        mx = max(mx, (int) ss.size());
        return mx;
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
 * problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 * solution: https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/1180181160/
 *
 */