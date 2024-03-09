#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void reverseString(vector<char> &s) {
        int len = s.size();
        int l = 0, r = len - 1;
        while (l < r) {
            char c = s[l];
            s[l] = s[r];
            s[r] = c;
            l++;
            r--;
        }
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
 * problem: https://leetcode.com/problems/reverse-string/description/
 * solution: https://leetcode.com/problems/reverse-string/submissions/1198868030/
 *
 */