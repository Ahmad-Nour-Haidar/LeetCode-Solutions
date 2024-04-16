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

    TreeNode *addOneRow(TreeNode *root, int val, int depth, int currentDepth = 1) {
        if (!root)return root;
        if (currentDepth > depth)return root;
        if (depth == currentDepth and depth == 1) {
            auto *node = new TreeNode(val);
            node->left = root;
            return node;
        }
        int newDepth = currentDepth + 1;
        if (newDepth == depth) {
            auto *temp1 = new TreeNode(val);
            auto *temp2 = new TreeNode(val);
            TreeNode *left = root->left;
            TreeNode *right = root->right;
            root->left = nullptr;
            root->right = nullptr;
            temp1->left = left;
            temp1->right = nullptr;
            root->left = temp1;
            temp2->right = right;
            temp2->left = nullptr;
            root->right = temp2;
            return root;
        }
        addOneRow(root->left, val, depth, newDepth);
        addOneRow(root->right, val, depth, newDepth);
        return root;
    }
};

int main() {
    int a[] = {4, 2, 6, 3, 1, 5};

    auto *node4 = new TreeNode(4);
    auto *node2 = new TreeNode(2);
    auto *node6 = new TreeNode(6);
    auto *node3 = new TreeNode(3);
    auto *node1 = new TreeNode(1);
    auto *node5 = new TreeNode(5);

    node4->left = node2;
    node4->right = node6;
    node2->left = node3;
    node2->right = node1;
    node6->left = node5;

    node4 = Solution().addOneRow(node4, 1, 1);

    queue<TreeNode *> q;
    q.emplace(node4);
    while (!q.empty()) {
        if (q.front()->left)
            q.emplace(q.front()->left);
        if (q.front()->right)
            q.emplace(q.front()->right);
        cout << q.front()->val << ' ';
        q.pop();
    }

    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/add-one-row-to-tree/description/
 * solution: https://leetcode.com/problems/add-one-row-to-tree/submissions/1234123678/
 *
 */