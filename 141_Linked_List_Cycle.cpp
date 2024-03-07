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
    bool hasCycle(ListNode *head) {
        if (!head)return false;
        int temp = 1e6; // 10^6
        while (head) {
            if (head->val == temp)return true;
            head->val = temp;
            head = head->next;
        }
        return false;
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
 * problem: https://leetcode.com/problems/linked-list-cycle/description/
 * solution: https://leetcode.com/problems/linked-list-cycle/submissions/1195493393/
 *
 */