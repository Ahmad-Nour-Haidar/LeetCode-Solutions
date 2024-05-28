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
    static bool checkEvenLevel(vector<int> &v) {
        int len = v.size();
        if (!(v[0] & 1))return false;
        for (int i = 1; i < len; ++i) {
            if (v[i] <= v[i - 1] or !(v[i] & 1))return false;
        }
        return true;
    }

    static bool checkOddLevel(vector<int> &v) {
        int len = v.size();
        if ((v[0] & 1))return false;
        for (int i = 1; i < len; ++i) {
            if (v[i] >= v[i - 1] or (v[i] & 1))return false;
        }
        return true;
    }

public:
    bool isEvenOddTree(TreeNode *root) {
        bool ans = true;
        // {node, level}
        queue<pair<TreeNode *, int> > q;
        q.emplace(root, 0);
        int currentLevel = 0;
        vector<int> v;
        while (!q.empty() and ans) {
            while (!q.empty() and q.front().second == currentLevel) {
                auto node = q.front().first;
                int level = q.front().second;
                q.pop();
                v.emplace_back(node->val);
                if (node->left)q.emplace(node->left, level + 1);
                if (node->right)q.emplace(node->right, level + 1);
            }
            if (currentLevel & 1) ans = checkOddLevel(v);
            else ans = checkEvenLevel(v);
            currentLevel++;
            v.clear();
        }
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
 * problem: https://leetcode.com/problems/even-odd-tree/description/
 * solution: https://leetcode.com/problems/even-odd-tree/submissions/1189324668/
 *
 */