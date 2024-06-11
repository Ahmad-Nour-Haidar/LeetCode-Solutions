#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
        int len1 = arr1.size();
        int mx = *max_element(arr1.begin(), arr1.end());
        mx++;
        int count[mx];
        vector<int> ans(len1);
        int currentIndex = 0;
        for (int &i:count)i = 0;
        for (int &i:arr1) count[i]++;
        for (int &i:arr2) {
            while (count[i]) {
                ans[currentIndex++] = i;
                count[i]--;
            }
        }
        for (int i = 0; i < mx; ++i) {
            while (count[i]) {
                ans[currentIndex++] = i;
                count[i]--;
            }
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
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/relative-sort-array/description/
 * solution: https://leetcode.com/problems/relative-sort-array/solutions/5297732/beats-100-00-of-users-with-c/
 *
 */