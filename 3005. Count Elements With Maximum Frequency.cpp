#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int> &nums) {
        int a[101] = {};
        for (auto it :nums)a[it]++;
        int mx = *max_element(a, a + 101);
        int c = count(a, a + 101, mx);
        return mx * c;
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
 * problem: https://leetcode.com/problems/count-elements-with-maximum-frequency/description/
 * solution: https://leetcode.com/problems/count-elements-with-maximum-frequency/solutions/4840714/beats-100-00-of-users-with-c-easy-solution/
 *
 */