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
    vector<int> helper(TreeNode *node, const int &distance, int &count) {
        if (!node) return {};

        // If it is a leaf node
        if (!node->left && !node->right) return {1};

        const auto leftDistances = helper(node->left, distance, count);
        const auto rightDistances = helper(node->right, distance, count);

        // Check pairs between left and right
        for (const int &ld : leftDistances) {
            for (const int &rd : rightDistances) {
                if (ld + rd <= distance) {
                    count++;
                }
            }
        }

        // Increase the distance by 1 for the parent
        vector<int> currentDistances;
        for (int ld : leftDistances) {
            if (ld + 1 <= distance) currentDistances.emplace_back(ld + 1);
        }
        for (int rd : rightDistances) {
            if (rd + 1 <= distance) currentDistances.emplace_back(rd + 1);
        }

        return currentDistances;
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int countPairs(TreeNode *root, const int &distance) {
        int count = 0;
        helper(root, distance, count);
        return count;
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
 * problem: https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/
 * solution: https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/solutions/5494363/beats-96-35
 *
 */