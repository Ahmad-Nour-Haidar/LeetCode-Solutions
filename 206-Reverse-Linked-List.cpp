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
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *reversedList = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return reversedList;
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
 * problem: https://leetcode.com/problems/reverse-linked-list/description/
 * solution: https://leetcode.com/problems/reverse-linked-list/solutions/4836727/beats-81-44-of-users-with-c-recursion/
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 */