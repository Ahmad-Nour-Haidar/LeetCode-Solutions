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
    int findBottomLeftValue(TreeNode *root) {
        int mx = 0;
        int ans = root->val;
        // this contain {node, depth}
        queue<pair<TreeNode *, int>> q;
        q.emplace(root, 0);
        while (!q.empty()) {
            auto node = q.front().first;
            int depth = q.front().second;
            q.pop();
            if (!node->left and !node->right) {
                if (depth > mx) {
                    mx = depth;
                    ans = node->val;
                }
            }
            if (node->left)q.emplace(node->left, depth + 1);
            if (node->right)q.emplace(node->right, depth + 1);
        }
        return ans;
    }
};

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/find-bottom-left-tree-value/description/
 * solution: https://leetcode.com/problems/find-bottom-left-tree-value/submissions/1188667834/
 *
 */