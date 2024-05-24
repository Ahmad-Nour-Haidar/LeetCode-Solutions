#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static bool canTake(const string &s, int *&countLetters) {
        int countLettersS[26]{};
        for (auto c :s)countLettersS[c - 'a']++;
        for (int i = 0; i < 26; ++i) {
            if (countLettersS[i] > countLetters[i])
                return false;
        }
        return true;
    }

    int help(const vector<string> &words, int *&scoreWords, int *&countLetters, int i) {
        if (i == words.size()) return 0;
        int res = help(words, scoreWords, countLetters, i + 1);
        if (canTake(words[i], countLetters)) {
            for (auto c :words[i])countLetters[c - 'a']--;
            res = max(res, scoreWords[i] + help(words, scoreWords, countLetters, i + 1));
            for (auto c :words[i])countLetters[c - 'a']++;
        }
        return res;
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score) {
        int lenWords = words.size();
        int *scoreWords = new int[lenWords];
        for (int i = 0; i < lenWords; ++i) {
            int s = 0;
            for (auto c:words[i]) s += score[c - 'a'];
            scoreWords[i] = s;
        }
        int *countLetters = new int[26]();
        for (auto c :letters)countLetters[c - 'a']++;
        return help(words, scoreWords, countLetters, 0);
    }
};

int main() {

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(2 ^ n)
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/maximum-score-words-formed-by-letters/description/
 * solution: https://leetcode.com/problems/maximum-score-words-formed-by-letters/solutions/5199904/beats-100-00-of-users-with-c/
 *
 */