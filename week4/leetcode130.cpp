class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int j = 0; j < n; ++j) {
            bfs(board, 0, j);
            bfs(board, m - 1, j);
        }
        for (int i = 0; i < m; ++i) {
            bfs(board, i, 0);
            bfs(board, i, n - 1);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '+') {
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }
    void bfs(vector<vector<char>>& board, int startX, int startY) {
        if (board[startX][startY] != 'O') {
            return;
        }
        int m = board.size();
        int n = board[0].size();
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        queue<pair<int, int>> que;
        que.push({startX, startY});
        board[startX][startY] = '+'; // 用 + 号标记是不能删除的 O
        while (!que.empty()) {
            pair<int, int> temp = que.front();
            que.pop();
            int curX = temp.first;
            int curY = temp.second;
            for (int i = 0; i < 4; ++i) {
                int nx = curX + dx[i];
                int ny = curY + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'O') {
                    board[nx][ny] = '+';
                    que.push({nx, ny});
                }
            }
        }
        return;
    }
private:
};