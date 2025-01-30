class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void DFS(int i, int j, vector<vector<bool>>& visit,vector<vector<char>>& adj) {
        int n = adj.size(), m = adj[0].size();
        visit[i][j] = true;
        for (auto it : dir) {
            int i_ = i + it[0];
            int j_ = j + it[1];
            if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && !visit[i_][j_] && adj[i_][j_] == 'O') {
                DFS(i_, j_, visit, adj);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            if (!visit[i][0] && board[i][0] == 'O') {
                DFS(i, 0, visit, board);
            }
            if (!visit[i][m - 1] && board[i][m - 1] == 'O') {
                DFS(i, m - 1, visit, board);
            }
        }
        for (int i = 0; i < m; i++) {
            if (!visit[0][i] && board[0][i] == 'O') {
                DFS(0, i, visit, board);
            }
            if (!visit[n - 1][i] && board[n - 1][i] == 'O') {
                DFS(n - 1, i, visit, board);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visit[i][j]&&board[i][j]=='O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};