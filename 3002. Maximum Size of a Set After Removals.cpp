#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumSetSize(vector<int> &nums1, vector<int> &nums2) {
        int len = nums1.size(), ans = 0;
        set<int> a, b;
        for (auto it :nums1)a.emplace(it);
        for (auto it :nums2)b.emplace(it);
        int c = 1;
        for (auto it:a) {
            if (c > len / 2)break;
            if (!b.count(it)) {
                c++;
                ans++;
            }
        }
        c = 1;
        for (auto it:b) {
            if (c > len / 2)break;
            if (!a.count(it)) {
                c++;
                ans++;
            }
        }
        if (ans < len) {
            for (auto it:b) {
                if (ans >= len)break;
                if (a.count(it))ans++;
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
 * Time Complexity: O(n*log(n))
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/maximum-size-of-a-set-after-removals/
 * solution: https://leetcode.com/problems/maximum-size-of-a-set-after-removals/submissions/1198217562/
 *
 */