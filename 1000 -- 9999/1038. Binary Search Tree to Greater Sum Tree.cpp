#include <bits/stdc++.h>

using namespace std;

//   Definition for a binary tree node.
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

    TreeNode *bstToGst(TreeNode *&root, int *sum = new int(0)) {
        if (!root) return nullptr;
        bstToGst(root->right, sum);
        root->val += *sum;
        *sum = root->val;
        bstToGst(root->left, sum);
        return root;
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
 * problem: https://leetcode.com/problems/height-checker/description/
 * solution: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/solutions/5365803/beats-100-00/
 *
 */