#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<int> frequencySort(vector<int> &nums) {
        int freq[201] = {0};
        for (const int &num : nums) freq[num + 100]++;
        sort(nums.begin(), nums.end(), [&freq](const int &a, const int &b) {
            if (freq[a + 100] == freq[b + 100]) {
                return a > b; // Sort in decreasing order if frequencies are the same
            }
            return freq[a + 100] < freq[b + 100]; // Sort in increasing order of frequency
        });
        return nums;
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
 * problem: https://leetcode.com/problems/sort-array-by-increasing-frequency/description/
 * solution: https://leetcode.com/problems/sort-array-by-increasing-frequency/solutions/5520979/beats-100-00
 *
 */