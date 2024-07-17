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
    TreeNode *helper(TreeNode *node, bool toDeleteArray[], vector<TreeNode *> &forest) {
        if (!node) return nullptr;

        node->left = helper(node->left, toDeleteArray, forest);
        node->right = helper(node->right, toDeleteArray, forest);

        if (toDeleteArray[node->val]) {
            if (node->left) forest.emplace_back(node->left);
            if (node->right) forest.emplace_back(node->right);
            delete node;
            return nullptr;
        }

        return node;
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
        bool toDeleteArray[1001] = {false};
        for (int val : to_delete) toDeleteArray[val] = true;

        vector<TreeNode *> forest;
        root = helper(root, toDeleteArray, forest);
        if (root) forest.emplace_back(root);
        return forest;
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
 * problem: https://leetcode.com/problems/delete-nodes-and-return-forest/description/
 * solution: https://leetcode.com/problems/delete-nodes-and-return-forest/solutions/5489390/beats-99-91
 *
 */