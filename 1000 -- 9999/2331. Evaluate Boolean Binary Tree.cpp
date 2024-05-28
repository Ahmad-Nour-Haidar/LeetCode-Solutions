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

    // 0 => false, 1 => true, 2 => or, 3 => and
    bool evaluateTree(TreeNode *root) {
        if (root->val == 0 or root->val == 1)return root->val;
        if (root->val == 2) {
            return evaluateTree(root->left) or evaluateTree(root->right);
        } else {
            return evaluateTree(root->left) and evaluateTree(root->right);
        }
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
 * problem: https://leetcode.com/problems/evaluate-boolean-binary-tree/description/
 * solution: https://leetcode.com/problems/evaluate-boolean-binary-tree/solutions/5163214/beats-100-00-of-users-with-c-runtime-0-ms-recursion/
 *
 */