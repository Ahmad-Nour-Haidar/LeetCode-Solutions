#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        int len = l1 + l2;
        int p1 = 0;
        int p2 = 0;
        int i = 0;
        int a[len];
        while (p1 < l1 and p2 < l2) {
            if (nums1[p1] < nums2[p2]) {
                a[i++] = nums1[p1++];
            } else {
                a[i++] = nums2[p2++];
            }
        }
        if (p1 not_eq l1) {
            for (int j = p1; j < l1; ++j) {
                a[i++] = nums1[j];
            }
        }
        if (p2 not_eq l2) {
            for (int j = p2; j < l2; ++j) {
                a[i++] = nums2[j];
            }
        }
        if (len % 2) {
            return a[len / 2];
        } else {
            return ((double) a[len / 2] + (double) a[len / 2 - 1]) / 2;
        }
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
 * problem: https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 * solution: https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/931877415/
 *
 */