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

    TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
        const int size = 1e5 + 5;

        unordered_map<int, TreeNode *> nodeMap; // Map to hold created nodes

        bool children[size]; // Array to track all child nodes
        for (auto &it:children)it = false;

        for (const auto &desc : descriptions) {
            int parent = desc[0];
            int child = desc[1];
            bool isLeft = desc[2] == 1;
            if (nodeMap.find(parent) == nodeMap.end()) {
                nodeMap[parent] = new TreeNode(parent);
            }
            if (nodeMap.find(child) == nodeMap.end()) {
                nodeMap[child] = new TreeNode(child);
            }
            if (isLeft) {
                nodeMap[parent]->left = nodeMap[child];
            } else {
                nodeMap[parent]->right = nodeMap[child];
            }
            children[child] = true;
        }
        // The root is the node that is never a child
        TreeNode *root = nullptr;
        for (const auto &pair : nodeMap) {
            if (!children[pair.first]) {
                root = pair.second;
                break;
            }
        }
        return root;
    }
};

int main() {

    vector<vector<int>> descriptions = {{20, 15, 1},
                                        {20, 17, 0},
                                        {50, 20, 1},
                                        {50, 80, 0},
                                        {80, 19, 1}};
    TreeNode *root = Solution().createBinaryTree(descriptions);

    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/create-binary-tree-from-descriptions/description/
 * solution: https://leetcode.com/problems/create-binary-tree-from-descriptions/solutions/5479213/runtime-beats-96-29-memory-beats-92-58
 *
 */