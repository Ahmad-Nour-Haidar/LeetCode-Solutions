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
    bool isPalindrome(ListNode *head) {
        auto *slow = head;
        auto *fast = head;
        while (fast and fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        auto *reversedList = reverseList(slow, nullptr);
        while (head and reversedList) {
            if (head->val not_eq reversedList->val)return false;
            head = head->next;
            reversedList = reversedList->next;
        }
        return true;
    }
};

int main() {
    int a[] = {1, 2, 3, 2, 1};
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

    cout << Solution().isPalindrome(head);

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * problem: https://leetcode.com/problems/palindrome-linked-list/description/
 * solution: https://leetcode.com/problems/palindrome-linked-list/solutions/4908287/beats-91-77-of-users-with-c-space-o-1-time-o-n-easy-solution/
 *
 */