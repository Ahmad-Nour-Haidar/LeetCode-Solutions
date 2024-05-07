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
private:
    int help(ListNode *head) {
        if (!head)return 0;
        head->val = head->val * 2 + help(head->next);
        int x = head->val / 10;
        head->val %= 10;
        return x;
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    ListNode *doubleIt(ListNode *head) {
        int x = help(head);
        if (x)head = new ListNode(x, head);
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
 * problem: https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/
 * solution: https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/solutions/5125756/beats-87-83-of-users-with-c/
 *
 */