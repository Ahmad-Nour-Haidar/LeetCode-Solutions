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
    ListNode *removeZeroSumSublists(ListNode *head) {
        vector<int> v;
        bool findNegative = false;
        auto temp = head;
        while (temp) {
            v.emplace_back(temp->val);
            findNegative |= (temp->val <= 0);
            temp = temp->next;
        }
        if (!findNegative)return head;
        for (int i = 0; i < v.size(); ++i) {
            int s = 0; // sum
            int end = i;
            int start = i;
            bool done = false;
            while (start >= 0) {
                s += v[start];
                if (s == 0) {
                    v.erase(v.begin() + start, v.begin() + end + 1);
                    done = true;
                    break;
                }
                start--;
            }
            if (done) {
                i = start - 1;
                if (i < 0)i = 0;
            }
        }
        head = temp = nullptr;
        for (auto it :v) {
            if (it == 0)continue;
            if (!head) {
                head = new ListNode(it);
                temp = head;
            } else {
                temp->next = new ListNode(it);
                temp = temp->next;
            }
        }
        return head;
    }
};

int main() {

    vector<int> v = {1, 2, 3, 4, 5};
    // erase: remove from first index to before last index
    v.erase(v.begin() + 2, v.begin() + 5);
    for (auto it:v)cout << it << ' ';


    // text example
    ListNode *head = nullptr;
    ListNode *temp = nullptr;
    v = {0, 0};
    for (auto it :v) {
        if (!head) {
            head = new ListNode(it);
            temp = head;
        } else {
            temp->next = new ListNode(it);
            temp = temp->next;
        }
    }
    head = Solution().removeZeroSumSublists(head);
    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }

    return 0;
}

/**
 * profile: https://leetcode.com/Ahmad_Nour_Haidar/
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 *
 * problem: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/
 * solution: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/submissions/1201327486/
 *
 */