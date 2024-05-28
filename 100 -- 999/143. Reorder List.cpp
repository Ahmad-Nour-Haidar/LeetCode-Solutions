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
    void reorderList(ListNode *head) {
        auto *temp = head->next;
        auto *reversedList = new ListNode(head->val); // this will contain reverse of head.
        auto *x = reversedList;
        int len = 1;
        while (temp) {
            len++;
            x->next = new ListNode(temp->val);
            x = x->next;
            temp = temp->next;
        }
        reversedList = reverseList(reversedList, nullptr);
        int i = 0;
        temp = head;
        x = reversedList;
        while (i < len / 2) {
            auto *next = temp->next;
            temp->next = new ListNode(x->val);
            temp->next->next = next;
            temp = temp->next->next;
            x = x->next;
            i++;
        }
        len--;
        temp = head;
        while (len--)temp = temp->next;
        temp->next = nullptr;
    }
};

int main() {
    int a[] = {1, 2, 3, 4};
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

    Solution().reorderList(head);

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/reorder-list/description/
 * solution: https://leetcode.com/problems/reorder-list/submissions/1211323582/
 *
 */