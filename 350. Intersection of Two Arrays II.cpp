#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int a[1001] = {}, b[1001] = {};
        int i = 0, j = 0, l1 = nums1.size(), l2 = nums2.size();
        while (i < l1 and j < l2) {
            if (nums1[i] == nums2[j]) {
                a[nums1[i]]++;
                b[nums2[j]]++;
                i++;
                j++;
            } else if (nums1[i] < nums2[j])i++;
            else if (nums1[i] > nums2[j])j++;
        }
        vector<int> ans;
        for (i = 0; i < 1001; ++i) {
            ans.insert(ans.end(), min(a[i], b[i]), i); // Add same value multiple times
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
 * problem: https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 * solution: https://leetcode.com/problems/intersection-of-two-arrays-ii/submissions/1198180740/
 *
 */