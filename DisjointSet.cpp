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