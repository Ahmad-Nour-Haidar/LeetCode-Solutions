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
private:
    ListNode *reverseList(ListNode *head, ListNode *end) {
        auto current = head;
        ListNode *ans = nullptr;
        while (current not_eq end) {
            auto next = current->next;
            current->next = ans;
            ans = current;
            current = next;
        }
        return ans;
    }

public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        auto *superHead = new ListNode(0, head);
        auto *beforeStart = superHead;
        auto *start = head;
        left--;
        while (left--) {
            beforeStart = start;
            start = start->next;
        }
        auto *end = head;
        right--;
        while (right--) end = end->next;
        auto *afterEnd = end->next;
        auto *temp = reverseList(start, afterEnd);
        auto *endTemp = temp;
        while (endTemp->next)endTemp = endTemp->next;
        beforeStart->next = temp;
        endTemp->next = afterEnd;
        return superHead->next;
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

    Solution().reverseBetween(head, 2, 4);

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/reverse-linked-list-ii/description/
 * solution: https://leetcode.com/problems/reverse-linked-list-ii/solutions/4904981/beats-100-00-of-users-with-c-space-complexity-o-1-time-complexity-o-n/
 *
 */