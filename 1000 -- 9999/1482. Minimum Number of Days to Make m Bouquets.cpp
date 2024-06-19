#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool hasSubarraysWithMaxValue(const vector<int> &bloomDay, const int &m, const int &k, const int &value) {
        int count = 0;
        int n = bloomDay.size();
        for (int i = 0; i < n; i++) {
            int items = 0;
            while (i < n && items < k && bloomDay[i] <= value) {
                items++;
                i++;
            }
            if (items == k) {
                count++;
                i--;
            }
            if (count >= m) {
                return true;
            }
        }
        return false;
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int minDays(vector<int> &bloomDay, const long long &m, const long long &k) {
        int n = bloomDay.size();
        if (m * k > n) return -1;
        int l = 1, r = 1e9, mid, ans;
        while (l <= r) {
            mid = (l + r) / 2;
            bool result = hasSubarraysWithMaxValue(bloomDay, m, k, mid);
            if (result) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
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
 * Time Complexity: O(n * log(n))
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/height-checker/description/
 * solution: https://leetcode.com/problems/height-checker/solutions/5287585/beats-100-00-of-users-with-c/
 *
 */