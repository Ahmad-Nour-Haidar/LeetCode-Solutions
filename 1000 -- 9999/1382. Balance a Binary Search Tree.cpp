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

    void traversalInOrder(vector<int> &v, TreeNode *root) {
        if (!root) return;

        traversalInOrder(v, root->left);

        v.emplace_back(root->val);

        traversalInOrder(v, root->right);
    }

    TreeNode *sortedArrayToBST(vector<int> &v, int start, int end) {
        if (start > end) return nullptr;

        int mid = (start + end) / 2;

        auto *root = new TreeNode(v[mid]);

        root->left = sortedArrayToBST(v, start, mid - 1);

        root->right = sortedArrayToBST(v, mid + 1, end);

        return root;
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    TreeNode *balanceBST(TreeNode *root) {
        vector<int> v;
        traversalInOrder(v, root);
        root = sortedArrayToBST(v, 0, v.size() - 1);
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
 * problem: https://leetcode.com/problems/balance-a-binary-search-tree/description/
 * solution: https://leetcode.com/problems/grumpy-bookstore-owner/solutions/5347313/beats-99-25/
 *
 */