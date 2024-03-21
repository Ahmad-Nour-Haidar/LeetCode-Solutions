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
    ListNode *reverseList(ListNode *head) {
        auto current = head;
        ListNode *ans = nullptr;
        while (current) {
            auto next = current->next;
            current->next = ans;
            ans = current;
            current = next;
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

    Solution().reverseList(head);

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 *
 * problem: https://leetcode.com/problems/reverse-linked-list/description/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * solution: https://leetcode.com/problems/reverse-linked-list/solutions/4836727/beats-81-44-of-users-with-c-recursion/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * solution: https://leetcode.com/problems/reverse-linked-list/solutions/4904219/time-complexity-o-n-space-complexity-o-1/
 *
 */