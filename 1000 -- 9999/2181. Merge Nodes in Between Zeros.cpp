#include <bits/stdc++.h>

using namespace std;

//  Definition for singly-linked list.
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

    ListNode *mergeNodes(ListNode *head) {
        ListNode *current = head->next;
        ListNode *mergedList = nullptr;
        ListNode *tail = nullptr;
        int sum = 0;

        while (current) {
            if (current->val == 0) {
                auto *newNode = new ListNode(sum);
                sum = 0;
                if (mergedList == nullptr) {
                    mergedList = newNode;
                    tail = mergedList;
                } else {
                    tail->next = newNode;
                    tail = tail->next;
                }
            } else {
                sum += current->val;
            }
            current = current->next;
        }
        return mergedList;
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
 * problem: https://leetcode.com/problems/merge-nodes-in-between-zeros/description/
 * solution: https://leetcode.com/problems/merge-nodes-in-between-zeros/solutions/5413976/beats-97-03
 *
 */