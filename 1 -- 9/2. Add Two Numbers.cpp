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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        auto *it1 = l1;
        auto *it2 = l2;
        ListNode *ans = nullptr;
        auto it = ans;
        int one = 0;
        while (it1 || it2) {
            int a = 0, b = 0;
            if (it1 != nullptr) {
                a = it1->val;
                it1 = it1->next;
            }
            if (it2 != nullptr) {
                b = it2->val;
                it2 = it2->next;
            }
            int c = a + b + one;
            int m = c % 10;
            one = c / 10;
            auto *node = new ListNode(m);
            if (ans == nullptr) {
                ans = node;
                it = ans;
            } else {
                it->next = node;
                it = it->next;
            }
        }
        if (one != 0) {
            auto *node = new ListNode(one);
            it->next = node;
        }
        return ans;
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
 * problem: https://leetcode.com/problems/add-two-numbers/description/
 * solution: https://leetcode.com/problems/add-two-numbers/submissions/1165791800/
 *
 */