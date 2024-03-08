#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(const string &s) {
        int zero = 0, one = 0;
        for (auto it:s) {
            zero += (it == '0');
            one += (it == '1');
        }
        string ans;
        one--;
        while (one) {
            ans += '1';
            one--;
        }
        while (zero) {
            ans += '0';
            zero--;
        }
        ans += '1';
        return ans;
    }
};

int main() {

    return 0;
}


/// profile: https://leetcode.com/Ahmad_Nour_Haidar/

/// Time Complexity: O(n)
/// Space Complexity: O(1)

/// problem: https://leetcode.com/problems/maximum-odd-binary-number/description/
/// solution: https://leetcode.com/problems/maximum-odd-binary-number/submissions/1190407195/
