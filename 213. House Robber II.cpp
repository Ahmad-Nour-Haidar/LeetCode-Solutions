//#include <bits/stdc++.h>
//
//using namespace std;
//// todo
//class Solution {
//public:
//
//    int dp[100 + 5][100000 + 5];
//
//    int max_to_steal(int idx, int amount, vector<int> &nums, int st_idx) {
//        if (st_idx == 1 && idx == nums.size() - 1) return 0;
//        if (idx == nums.size()) return 0;
//
//        int &ret = dp[idx][amount];
//        if (~ret) return ret;
//
//        int ch1 = max_to_steal(idx + 2, amount + nums[idx], nums, st_idx == -1 ? 1 : st_idx) + nums[idx]; //taken
//        int ch2 = max_to_steal(idx + 1, amount, nums, st_idx == -1 ? 0 : st_idx);
//
//        return ret = max(ch1, ch2);
//    }
//
//    int rob(vector<int> &nums) {
//        memset(dp, -1, sizeof(dp));
//        int x = 7;
//        return max_to_steal(0, 0, nums, -1);
//    }
//};
//
//int main() {
//
//    vector<int> v = {1, 2, 3};
//
//    cout << Solution().rob(v);
//
//    return 0;
//}
//
//
///**
// * profile: https://leetcode.com/Ahmad_Nour_Haidar/
// *
// * Time Complexity: O(n)
// * Space Complexity: O()
// *
// * problem: https://leetcode.com/problems/house-robber-ii/description/
// * solution: https://leetcode.com/problems/number-of-wonderful-substrings/solutions/5092400/beats-53-89-of-users-with-c/
// *
// */