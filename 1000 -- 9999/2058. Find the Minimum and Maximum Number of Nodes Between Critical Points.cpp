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
private:
    static bool isLocalMaxima(ListNode *previous, ListNode *current) {
        return previous and current->next and current->val > previous->val and current->val > current->next->val;
    }

    static bool isLocalMinima(ListNode *previous, ListNode *current) {
        return previous and current->next and current->val < previous->val and current->val < current->next->val;
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<int> nodesBetweenCriticalPoints(ListNode *head) {
        ListNode *previous = nullptr;
        ListNode *current = head;
        int index = 0, firstIndex = -1, lastIndex = -1, count = 0;
        int mn = 1e9;
        while (current) {
            if (isLocalMaxima(previous, current) || isLocalMinima(previous, current)) {
                count++;
                if (count == 1) firstIndex = index;
                if (count > 1) {
                    mn = min(mn, index - lastIndex);
                }
                lastIndex = index;
            }
            index++;
            previous = current;
            current = current->next;
        }

        if (count <= 1)
            return {-1, -1};

        return {mn, lastIndex - firstIndex};
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
 * problem: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/
 * solution: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/solutions/5420151/beats-98-90
 *
 */