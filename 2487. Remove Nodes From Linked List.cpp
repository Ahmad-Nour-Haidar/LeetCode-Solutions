#include <bits/stdc++.h>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    ListNode *removeNodes(ListNode *head) {
        if (head == nullptr)return nullptr;
        if (!head->next)return head;
        head->next = removeNodes(head->next);
        if (head->next and head->val < head->next->val) {
            return head->next;
        }
        return head;
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
 * problem: https://leetcode.com/problems/remove-nodes-from-linked-list/description/
 * solution: https://leetcode.com/problems/remove-nodes-from-linked-list/solutions/5118973/beats-99-39-of-users-with-c/
 *
 */