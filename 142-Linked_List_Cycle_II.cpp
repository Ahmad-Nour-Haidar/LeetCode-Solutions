#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head or !head->next)return nullptr;
        set<ListNode *> s;
        while (head) {
            if (head->next and s.count(head->next))return head->next;
            s.emplace(head);
            head = head->next;
        }
        return nullptr;
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
 * problem: https://leetcode.com/problems/linked-list-cycle-ii/description/
 * solution: https://leetcode.com/problems/linked-list-cycle-ii/submissions/1195528451/
 *
 */