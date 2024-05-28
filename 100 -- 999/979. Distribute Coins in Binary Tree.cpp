#include <bits/stdc++.h>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int ans = 0;

    int dfs(TreeNode *root) {
        if (!root)return 0;
        if (!root->left and !root->right) {
            int extra = root->val - 1;
            ans += abs(extra);
            return extra;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        int extra = root->val - 1 + left + right;
        ans += abs(extra);
        return extra;
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int distributeCoins(TreeNode *root) {
        dfs(root);
        return ans;
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
 * problem: https://leetcode.com/problems/distribute-coins-in-binary-tree/description/
 * solution: https://leetcode.com/problems/distribute-coins-in-binary-tree/solutions/5172969/beats-100-00-of-users-with-c/
 *
 */