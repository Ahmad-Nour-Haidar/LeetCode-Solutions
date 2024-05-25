#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static string join(const vector<string> &vec, const string &delimiter = " ") {
        ostringstream oss;
        int n = vec.size();
        for (size_t i = 0; i < n; ++i) {
            if (i != 0) {
                oss << delimiter;
            }
            oss << vec[i];
        }
        return oss.str();
    }

    void
    help(const string &s, vector<string> &ans, const set<string> &words, vector<string> &current, const int &length,
         int i) {
        if (i == length) {
            ans.emplace_back(join(current));
        }
        for (int j = i; j < length; ++j) {
            string newS = s.substr(i, j - i + 1);
            if (words.count(newS)) {
                current.emplace_back(newS);
                help(s, ans, words, current, length, j + 1);
                current.pop_back();
            }
        }
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<string> wordBreak(const string &s, const vector<string> &wordDict) {
        set<string> words;
        for (const auto &it : wordDict)words.emplace(it);
        vector<string> ans;
        vector<string> current;
        help(s, ans, words, current, s.length(), 0);
        return ans;
    }
};

int main() {

    string s = "catsanddog";
    vector<string> v = {"cat", "cats", "and", "sand", "dog"};
    Solution().wordBreak(s, v);

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(2 ^ n)
 * Space Complexity: O(2 ^ n)
 *
 * problem: https://leetcode.com/problems/word-break-ii/description/
 * solution: https://leetcode.com/problems/word-break-ii/solutions/5204128/beats-100-00-of-users-with-c/
 *
 */