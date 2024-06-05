#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<string> commonChars(vector<string> &words) {
        int count[26] = {};
        int minFound[26];
        for (auto &it:minFound)it = INT_MAX;
        for (auto &it:words) {
            int tempCount[26] = {};
            for (auto &c:it) {
                tempCount[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                if (tempCount[i]) {
                    minFound[i] = min(minFound[i], tempCount[i]);
                    count[i]++;
                }
            }
        }
        vector<string> ans;
        int len = words.size();
        for (int i = 0; i < 26; ++i) {
            if (count[i] == len) {
                for (int j = 0; j < minFound[i]; ++j) {
                    char c = i + 'a';
                    string s;
                    s += c;
                    ans.emplace_back(s);
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<string> v = {"bella", "label", "roller"};
    Solution().commonChars(v);
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n * m)
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/find-common-characters/description/
 * solution: https://leetcode.com/problems/find-common-characters/solutions/5262063/beats-100-00-of-users-with-c/
 *
 */