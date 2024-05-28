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

    int solve(TreeNode *root) {
        if (!root)return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        ans = max(ans, (left + right + 1));
        return max(left, right) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root) {
        solve(root);
        return ans - 1;
    }
};
/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/diameter-of-binary-tree/description/
 * solution: https://leetcode.com/problems/diameter-of-binary-tree/submissions/1187399658/
 *
 */