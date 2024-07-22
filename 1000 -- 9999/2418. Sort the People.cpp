#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<string> sortPeople(vector<string> &names, vector<int> &heights) {
        int n = names.size();
        pair<int, string> people[n];
        for (int i = 0; i < n; ++i) {
            people[i] = {heights[i], names[i]};
        }
        sort(people, people + n, [](const pair<int, string> &a, const pair<int, string> &b) {
            return b.first < a.first;
        });
        vector<string> sortedNames;
        for (const auto &person : people) {
            sortedNames.emplace_back(person.second);
        }
        return sortedNames;
    }
};

int main() {
    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n * log(n))
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/sort-the-people/description/
 * solution: https://leetcode.com/problems/sort-the-people/solutions/5517972/beats-98-98
 *
 */