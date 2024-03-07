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
    int pairSum(ListNode *head) {
        auto *slow = head;
        auto *fast = head;
        // find middle
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto *mid = slow;
        stack<ListNode *> s;
        while (slow) {
            s.emplace(slow);
            slow = slow->next;
        }
        slow = head;
        int ans = 0;
        while (slow not_eq mid) {
            int top = s.top()->val;
            s.pop();
            ans = max(ans, slow->val + top);
            slow = slow->next;
        }
        return ans;
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

    Solution().pairSum(head);

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/
 * solution: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/solutions/4836887/easy/
 *
 */