class DisjointSet {
private:
    int *size, *parent, n;

    void initial() {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

public:
    explicit DisjointSet(int n) {
        size = new int[n];
        parent = new int[n];
        this->n = n;
        initial();
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
        if (a == b) return;
        if (size[a] > size[b]) {
            parent[b] = a;
            size[a] += size[b];
        } else {
            parent[a] = b;
            size[b] += size[a];
        }
    }
};