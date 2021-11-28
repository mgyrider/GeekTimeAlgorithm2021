class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        fa = vector<int>(total, -1);
        // 初始化
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    fa[i * n + j] = i * n + j;
                }
            }
        }
        int dx[] = {1, 0};
        int dy[] = {0, 1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int id = i * n + j;
                if (grid[i][j] != '1') {
                    continue;
                }
                // 合并右边和下边的陆地
                for (int k = 0; k < 2; ++k) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    int nid = nx * n + ny;
                    if (nx >= m || ny >= n || grid[nx][ny] != '1') {
                        continue;
                    }
                    merge(id, nid);
                }
            }
        }
        // 统计岛屿数量
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (fa[i * n + j] == i * n + j) {
                    ans++;
                }
            }
        }
        return ans;
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