class Solution {
public:
#define p pair<int, pair<int, int>>
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<p, vector<p>, greater<p>> qu;
        qu.push({0, {0, 0}});
        result[0][0] = 0;
        vector<vector<int>> visit(m, vector<int>(n, false));
        while (!qu.empty()) {
            int wit = qu.top().first;
            int i = qu.top().second.first;
            int j = qu.top().second.second;
            qu.pop();
            if(i==m-1 && j==n-1){
                return result[m-1][n-1];
            }
            if (visit[i][j] == true) {
                continue;
            }
            visit[i][j] = true;
            for (auto& it : dir) {
                int ci = i + it[0];
                int cj = j + it[1];
                if (ci < 0 || ci >= m || cj < 0 || cj >= n) {
                    continue;
                }
                if (grid[ci][cj] <= wit + 1) {
                    qu.push({wit + 1, {ci, cj}});
                    result[ci][cj] = wit + 1;
                } else if ((grid[ci][cj]-wit) % 2 == 0) {
                    qu.push({grid[ci][cj] + 1, {ci, cj}});
                    result[ci][cj] = grid[ci][cj] + 1;
                } else {
                    qu.push({grid[ci][cj], {ci, cj}});
                    result[ci][cj] = grid[ci][cj];
                }
            }
        }
        return result[m - 1][n - 1];
    }
};