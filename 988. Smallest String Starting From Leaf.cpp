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
    string ans = "";
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    /// DFS
    string smallestFromLeaf(TreeNode *root, string current = "") {
        if (!root) return "";
        char c = root->val + 'a'; // 0 + 'a' => a, 1 + 'a' = 'b' ...
        current = c + current;
        if (!root->left and !root->right) {
            if (ans.empty() or ans > current) {
                ans = current;
            }
        }
        smallestFromLeaf(root->left, current);
        smallestFromLeaf(root->right, current);
        return ans;
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
 * problem: https://leetcode.com/problems/smallest-string-starting-from-leaf/description/
 * solution: https://leetcode.com/problems/smallest-string-starting-from-leaf/solutions/5034708/8-ms-easy-short-way/
 *
 */