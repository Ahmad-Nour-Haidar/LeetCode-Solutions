#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
        map<int, int> m;
        for (auto it:arr) {
            m[it]++;
        }
        int len = m.size();
        pair<int, int> p[len];
        int i = 0;
        for (auto it:m) {
            p[i] = {it.second, it.first};
            i++;
        }
        sort(p, p + len);
        int c = 0;
        for (auto it:p) {
            if (k >= it.first)k -= it.first, c++;
            else break;
        }
        return len - c;
    }
};

int main() {

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n log(n) )
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/
 * solution: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/submissions/1176626325/
 *
 */