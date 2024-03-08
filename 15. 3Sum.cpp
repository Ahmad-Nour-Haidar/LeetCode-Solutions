#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    struct Triplet {
        int a, b, c;

        Triplet(int a, int b, int c) : a(a), b(b), c(c) {}

        bool operator<(const Triplet &other) const {
            if (a != other.a) return a < other.a;
            if (b != other.b) return b < other.b;
            return c < other.c;
        }
    };

public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        set<Triplet> s;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            int j = i + 1, k = len - 1;
            while (j < k) {
                int x = nums[i] + nums[j] + nums[k];
                if (x == 0) {
                    s.emplace(Triplet(nums[i], nums[j], nums[k]));
                    j++;
                    k--;
                } else if (x < 0)j++;
                else k--;
            }
        }
        vector<vector<int>> ans;
        for (auto it:s) {
            ans.emplace_back(vector<int>{it.a, it.b, it.c});
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
 * Space Complexity: ~O(n)
 *
 * problem: https://leetcode.com/problems/3sum/description/
 * solution: https://leetcode.com/problems/3sum/solutions/4818301/solved-by-struct-triplet-set/
 *
 */