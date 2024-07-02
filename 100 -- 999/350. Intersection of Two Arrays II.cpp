#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int i = 0, j = 0, l1 = nums1.size(), l2 = nums2.size();
        while (i < l1 and j < l2) {
            if (nums1[i] == nums2[j]) {
                ans.emplace_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) i++;
            else j++;
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
 * problem: https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 * solution: https://leetcode.com/problems/intersection-of-two-arrays-ii/solutions/5400481/beats-100-00
 *
 */