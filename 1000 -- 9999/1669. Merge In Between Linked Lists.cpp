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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
        ListNode *p1 = list1, *p2 = list1;
        a--;
        while (a--) p1 = p1->next;
        while (b--) p2 = p2->next;
        ListNode *endList2 = list2;
        while (endList2->next)endList2 = endList2->next;
        p1->next = list2;
        endList2->next = p2->next;
        return list1;
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
 * problem: https://leetcode.com/problems/merge-in-between-linked-lists/description/
 * solution: https://leetcode.com/problems/merge-in-between-linked-lists/solutions/4899334/beats-83-95-of-users-with-c-time-complexity-o-n-space-complexity-o-1/
 *
 */