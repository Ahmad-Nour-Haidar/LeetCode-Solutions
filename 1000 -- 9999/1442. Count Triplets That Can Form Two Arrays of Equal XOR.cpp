#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int countTriplets(vector<int> &arr) {
        int n = arr.size() + 1;
        int pre[n + 1];
        pre[0] = 0;
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i - 1] ^ arr[i - 1];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (pre[i] == pre[j])
                    ans += j - i - 1;
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
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/
 * solution: https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/solutions/5230286/beats-100-00-of-users-with-c/
 *
 */