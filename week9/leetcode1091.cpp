class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        beginDepth = vector<vector<int>> (n, vector<int>(n, 0));
        endDepth = vector<vector<int>> (n, vector<int>(n, 0));
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }
        if (n == 1) {
            return 1;
        }
        beginQue.push({0, 0});
        endQue.push({n - 1, n - 1});
        beginDepth[0][0] = endDepth[n - 1][n - 1] = 1;
        int ret = -1;
        //　双向BFS
        while (!beginQue.empty() && !endQue.empty()) {
            ret = expend(grid, beginQue, beginDepth, endDepth);
            if (ret > 0) {
                break;
            }
            ret = expend(grid, endQue, endDepth, beginDepth);
            if (ret > 0) {
                break;
            }
        }
        return ret;
    }
private:
    queue<pair<int, int>> beginQue;
    vector<vector<int>> beginDepth;
    queue<pair<int, int>> endQue;
    vector<vector<int>> endDepth;
    int expend(vector<vector<int>>& grid, queue<pair<int, int>>& curQue, vector<vector<int>>& curDepth,
        vector<vector<int>>& otherDepth) {
        int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int len = curQue.size();
        int n = grid.size();
        while (len > 0) {
            auto temp = curQue.front();
            curQue.pop();
            int x = temp.first;
            int y = temp.second;
            for (int i = 0; i < 8; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                    if (otherDepth[nx][ny] != 0) {
                        //　找到了通路
                        return curDepth[x][y] + otherDepth[nx][ny];
                    } else if (curDepth[nx][ny] == 0) {
                        curDepth[nx][ny] = curDepth[x][y] + 1;
                        curQue.push({nx, ny});
                    }
                }
            }
            len--;
        }
        return -1;
    }
};