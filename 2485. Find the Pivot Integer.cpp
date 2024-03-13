#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        int sum = n * (n + 1) / 2; // sum 1 -> n
        int l = 1, r = n, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int temp1 = mid * (mid + 1) / 2; // sum 1 -> mid
            int temp2 = sum - ((mid - 1) * (mid) / 2); // sum mid -> n
            if (temp1 == temp2) {
                ans = mid;
                break;
            } else if (temp1 > temp2)r = mid - 1;
            else l = mid + 1;
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
 * Time Complexity: O(log(n))
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/find-the-pivot-integer/description/
 * solution: https://leetcode.com/problems/find-the-pivot-integer/solutions/4867042/beats-100-00-of-users-with-c-binary-search/
 *
 */