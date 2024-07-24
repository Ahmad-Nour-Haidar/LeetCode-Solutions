#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int convert(const vector<int> &mapping, int num) {
        if (num == 0) return mapping[0];
        int mappedValue = 0;
        int place = 1;
        while (num > 0) {
            int digit = num % 10;
            mappedValue = mapping[digit] * place + mappedValue;
            place *= 10;
            num /= 10;
        }
        return mappedValue;
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums) {
        vector<pair<int, int>> mappedNums;

        // Convert each number in nums to its mapped value and store with the original index
        for (int i = 0; i < nums.size(); ++i) {
            mappedNums.emplace_back(convert(mapping, nums[i]), i);
        }

        // Sort based on the mapped values, using the original index to maintain relative order
        sort(mappedNums.begin(), mappedNums.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            if (a.first == b.first) {
                return a.second < b.second; // Maintain relative order if mapped values are the same
            }
            return a.first < b.first;
        });

        // Generate the sorted result based on the original indices
        vector<int> ans;
        for (const auto &p : mappedNums) {
            ans.emplace_back(nums[p.second]);
        }

        return ans;
    }
};

int main() {
    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n * log(n))
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/sort-the-jumbled-numbers/description/
 * solution: https://leetcode.com/problems/sort-the-jumbled-numbers/solutions/5526308/beats-100-00
 *
 */