#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    string removeKdigits(string &num, int k) {
        stack<char> s;
        for (auto it :num) {
            while (!s.empty() and k and s.top() > it) {
                s.pop();
                k--;
            }
            s.emplace(it);
        }
        while (k) {
            s.pop();
            k--;
        }
        num.clear();
        while (!s.empty()) {
            num += s.top();
            s.pop();
        }
        reverse(num.begin(), num.end());
        auto i = num.find_first_not_of('0');
        if (i < num.length())num = num.substr(i);
        else num = '0';
        if (num.empty())num = '0';
        return num;
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
 * problem: https://leetcode.com/problems/remove-k-digits/description/
 * solution: https://leetcode.com/problems/remove-k-digits/submissions/1229674343/
 *
 */