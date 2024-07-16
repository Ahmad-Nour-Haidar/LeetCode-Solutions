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
    TreeNode *findLCA(TreeNode *root, int startValue, int destValue) {
        if (!root) return nullptr;
        if (root->val == startValue or root->val == destValue) return root;

        const auto left = findLCA(root->left, startValue, destValue);
        const auto right = findLCA(root->right, startValue, destValue);

        if (left && right) return root;
        return left ? left : right;
    }

    bool findPath(TreeNode *root, int value, string &path) {
        if (!root) return false;
        if (root->val == value) return true;

        path.push_back('L');
        if (findPath(root->left, value, path)) return true;
        path.pop_back();

        path.push_back('R');
        if (findPath(root->right, value, path)) return true;
        path.pop_back();

        return false;
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    string getDirections(TreeNode *root, const int &startValue, const int &destValue) {
        const auto lca = findLCA(root, startValue, destValue);

        string pathToStart, pathToDest;
        findPath(lca, startValue, pathToStart);
        findPath(lca, destValue, pathToDest);

        for (char &c : pathToStart) c = 'U';

        return pathToStart + pathToDest;
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
 * problem: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/
 * solution: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/solutions/5484585/beats-100-00
 *
 */