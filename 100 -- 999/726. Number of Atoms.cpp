#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    string countOfAtoms(const string &formula) {
        stack<map<string, int>> stk;
        map<string, int> current;
        const int n = formula.size();
        int i = 0;

        while (i < n) {
            if (formula[i] == '(') {
                stk.push(current);
                current.clear();
                i++;
            } else if (formula[i] == ')') {
                i++;
                const int start = i;
                while (i < n && isdigit(formula[i])) i++;
                int multiplicity = (start == i) ? 1 : stoi(formula.substr(start, i - start));
                if (!stk.empty()) {
                    const map<string, int> temp = current;
                    current = stk.top();
                    stk.pop();
                    for (const auto &p : temp) {
                        current[p.first] += p.second * multiplicity;
                    }
                }
            } else {
                int start = i;
                i++;
                while (i < n && islower(formula[i])) i++;
                const string name = formula.substr(start, i - start);
                start = i;
                while (i < n && isdigit(formula[i])) i++;
                const int multiplicity = (start == i) ? 1 : stoi(formula.substr(start, i - start));
                current[name] += multiplicity;
            }
        }

        string result;
        for (const auto &it : current) {
            result += it.first;
            if (it.second > 1) result += to_string(it.second);
        }
        return result;
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
 * problem: https://leetcode.com/problems/number-of-atoms/description/
 * solution: https://leetcode.com/problems/number-of-atoms/solutions/5473629/beats-100-00G
 *
 */