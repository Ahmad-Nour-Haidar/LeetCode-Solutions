#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void quickSort(vector<int> &nums, int left, int right) {
        if (left >= right) return;

        // Choosing the pivot element as the middle of the segment
        int pivotIndex = left + (right - left) / 2;
        int pivotValue = nums[pivotIndex];
        int i = left;
        int j = right;

        // Partitioning the array based on the pivot value
        while (i <= j) {
            while (nums[i] < pivotValue) i++;
            while (nums[j] > pivotValue) j--;
            if (i <= j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }

        // Recursively sort the left and right subarrays
        if (left < j) quickSort(nums, left, j);
        if (i < right) quickSort(nums, i, right);
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<int> sortArray(vector<int> &nums) {
//        sort(nums.begin(), nums.end());
        quickSort(nums, 0, nums.size() - 1);
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
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/sort-an-array/description/
 * solution:https://leetcode.com/problems/sort-an-array/solutions/5533119/quick-sort
 *
 */