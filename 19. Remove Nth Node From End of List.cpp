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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        auto *temp = new ListNode(0, head);
        auto left = temp;
        auto right = head;
        while (n and right) {
            right = right->next;
            n--;
        }
        while (right) {
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;
        return temp->next;
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
 * problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 * solution: https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/1192920605/
 *
 */