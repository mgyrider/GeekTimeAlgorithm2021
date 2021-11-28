class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        /* 
         * 将边上的点加入到并查集，如果两个点在同一个集合中，说明构成了环，
         * 新加入的这条边，就是构成环的最后一条边，即答案
         */
        int m = edges.size();
        int n = 1000;
        fa = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            fa[i] = i;
        }
        for (auto e : edges) {
            if (find(e[0]) == find(e[1])) {
                return e;
            }
            merge(e[0], e[1]);
        }
        return {};
    }
private:
    vector<int> fa;
    int find(int root) {
        if (fa[root] == root) {
            return root;
        }
        return fa[root] = find(fa[root]);
    }
    void merge(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        fa[ra] = rb;
        return;
    }
};