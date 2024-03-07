#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *deleteMiddle(ListNode *head) {
        if (!head->next)return nullptr;
        auto *before = head;
        auto *slow = head;
        auto *fast = head;
        while (fast and fast->next) {
            before = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        before->next = slow->next;
        return head;
    }
};

int main() {
    int a[] = {1, 2, 3, 4, 5};
    ListNode *head = nullptr;
    ListNode *temp = nullptr;
    for (auto it :a) {
        if (!head) {
            head = new ListNode(it);
            temp = head;
        } else {
            temp->next = new ListNode(it);
            temp = temp->next;
        }
    }

    Solution().deleteMiddle(head);

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
 * solution: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/solutions/4836073/beats-92-49-of-users-with-c-o-1-memory-simple-clear-solution/
 *
 */