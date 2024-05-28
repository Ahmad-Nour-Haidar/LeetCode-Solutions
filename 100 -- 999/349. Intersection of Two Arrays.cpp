#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        bool taken[1001] = {};
        vector<int> ans;
        int i = 0, j = 0, l1 = nums1.size(), l2 = nums2.size();
        while (i < l1 and j < l2) {
            if (nums1[i] == nums2[j]) {
                !taken[nums1[i]] ? ans.emplace_back(nums1[i]) : 1;
                taken[nums1[i]] = true;
                i++;
                j++;
            } else if (nums1[i] < nums2[j])i++;
            else if (nums1[i] > nums2[j])j++;
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
 * problem: https://leetcode.com/problems/intersection-of-two-arrays/description/
 * solution: https://leetcode.com/problems/intersection-of-two-arrays/submissions/1198161241/
 *
 */