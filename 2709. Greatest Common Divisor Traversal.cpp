#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
private:
    int *size, *parent, n;

    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }

    void makeSets() {
        for (int i = 0; i < n; i++) {
            make_set(i);
        }
    }

public:
    explicit DisjointSet(int n) {
        size = new int[n];
        parent = new int[n];
        this->n = n;
        makeSets();
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    // we attach the tree with the lower rank to the one with the bigger rank. rank = size
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a not_eq b) {
            if (size[a] > size[b]) {
                parent[b] = a;
                size[a] += size[b];
            } else {
                parent[a] = b;
                size[b] += size[a];
            }
        }
    }

};

class Solution {
public:
    bool canTraverseAllPairs(vector<int> &nums) {
        int len = nums.size();
        auto disjointSet = DisjointSet(len);
        // this array will contain the factor and the first index appear in it {factor, index}
        int mx = *max_element(nums.begin(), nums.end());
        mx++;
        int m[mx];
        for (int i = 0; i < mx; ++i) {
            m[i] = -1;
        }
        for (int i = 0; i < len; ++i) {
            int x = 2;
            while (x * x <= nums[i]) {
                if (nums[i] % x == 0) {
                    if (m[x] not_eq -1) {
                        disjointSet.union_sets(i, m[x]);
                    } else {
                        m[x] = i;
                    }
                    while (nums[i] % x == 0) {
                        nums[i] /= x;
                    }
                }
                x++;
            }
            if (nums[i] > 1) {
                if (m[nums[i]] not_eq -1) {
                    disjointSet.union_sets(i, m[nums[i]]);
                } else {
                    m[nums[i]] = i;
                }
            }
        }
        set<int> s;
        for (int i = 0; i < len; ++i) {
            int x = disjointSet.find_set(i);
            cout << x << ' ';
            s.emplace(x);
        }
        return s.size() == 1;
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
 * problem: https://leetcode.com/problems/greatest-common-divisor-traversal/description/
 * solution: https://leetcode.com/problems/greatest-common-divisor-traversal/submissions/1185736459/
 *
 */