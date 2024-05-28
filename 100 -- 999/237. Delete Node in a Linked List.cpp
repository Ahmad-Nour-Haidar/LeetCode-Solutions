#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    void deleteNode(ListNode *node) {
        while (node and node->next) {
            node->val = node->next->val;
            if (!node->next->next)node->next = nullptr;
            node = node->next;
        }
    }
};

int main() {
    return 0;
}


/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/delete-node-in-a-linked-list/description/
 * solution: https://leetcode.com/problems/delete-node-in-a-linked-list/solutions/5113978/beats-100-00-of-users-with-c/
 *
 */