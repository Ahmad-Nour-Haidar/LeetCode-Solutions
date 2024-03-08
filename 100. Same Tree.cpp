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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p and !q)return true;
        if (!p and q)return false;
        if (p and !q)return false;
        queue<TreeNode *> q1, q2;
        auto p1 = p;
        auto p2 = q;
        q1.emplace(p1);
        q2.emplace(p2);
        while (!q1.empty() and !q2.empty()) {
            p1 = q1.front();
            p2 = q2.front();
            q1.pop();
            q2.pop();
            if (!p1 and p2)return false;
            if (p1 and !p2)return false;
            if (p1->val not_eq p2->val) return false;
            if (!p1->left and p2->left) return false;
            if (p1->left and !p2->left) return false;
            if (!p1->right and p2->right) return false;
            if (p1->right and !p2->right) return false;
            if (p1->left)q1.emplace(p1->left);
            if (p1->right)q1.emplace(p1->right);
            if (p2->left)q2.emplace(p2->left);
            if (p2->right)q2.emplace(p2->right);
        }
        return q1.size() == q2.size();
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
 * problem: https://leetcode.com/problems/same-tree/description/
 * solution: https://leetcode.com/problems/same-tree/solutions/4785473/same-tree-solution/
 *
 */