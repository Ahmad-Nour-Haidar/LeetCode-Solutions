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
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int sumOfLeftLeaves(TreeNode *root) {
        if (!root)return 0;
        int x = 0;
        if (root->left and !root->left->left and !root->left->right)x = root->left->val;
        return x + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
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
 * problem: https://leetcode.com/problems/sum-of-left-leaves/description/
 * solution: https://leetcode.com/problems/sum-of-left-leaves/solutions/5021993/beats-100-00-of-users-with-c-easy-way/
 *
 */