#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    string stack_to_string(stack<char> &st) {
        string result;
        result.reserve(st.size()); // Reserve memory to avoid multiple reallocations
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end()); // Reverse the string to get the correct order
        return result;
    }

    int calc(const string &s, stack<char> &st, const string &sub, const int &value) {
        int ans = 0;
        for (const char &ch : s) {
            if (!st.empty() and st.top() == sub[0] and ch == sub[1]) {
                ans += value;
                st.pop();
            } else {
                st.emplace(ch);
            }
        }
        return ans;
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int maximumGain(const string &s, const int &x, const int &y) {
        const string big = (x > y) ? "ab" : "ba";
        const string small = (x > y) ? "ba" : "ab";
        const int bigScore = max(x, y);
        const int smallScore = min(x, y);
        stack<char> st;
        int ans = 0;
        ans += calc(s, st, big, bigScore);
        const string remaining = stack_to_string(st);
        ans += calc(remaining, st, small, smallScore);
        return ans;
    }
};

int main() {

    string s = "aabbabkbbbfvybssbtaobaaaabataaadabbbmakgabbaoapbbbbobaabvqhbbzbbkapabaavbbeghacabamdpaaqbqabbjbababmbakbaabajabasaabbwabrbbaabbafubayaazbbbaababbaaha";
    int x = 1926, y = 4320;
    cout << Solution().maximumGain(s, x, y);

    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/maximum-score-from-removing-substrings/description/
 * solution: https://leetcode.com/problems/maximum-score-from-removing-substrings/solutions/5464032/using-stack
 *
 */