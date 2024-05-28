#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2) {
        int i = 0, j = 0, l1 = nums1.size(), l2 = nums2.size();
        while (i < l1 and j < l2) {
            if (nums1[i] == nums2[j])return nums1[i];
            if (nums1[i] < nums2[j])i++;
            else if (nums1[i] > nums2[j])j++;
        }
        return -1;
    }
};

int main() {

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/minimum-common-value/description/
 * solution: https://leetcode.com/problems/minimum-common-value/submissions/1198138972/
 *
 */