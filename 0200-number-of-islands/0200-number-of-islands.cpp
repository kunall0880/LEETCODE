class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    // void dfs(int i,int j,vector<vector<char>>&grid){
    //     int m=grid.size(),n=grid[0].size();
    //     grid[i][j]='0';
    //     for(auto it : dir){
    //         int i_=i+it[0];
    //         int j_=j+it[1];
    //         if(i_>=0&&i_<m&&j_>=0&&j_<n&&grid[i_][j_]=='1'){
    //             //grid[i_][j_]=0;
    //             dfs(i_,j_,grid);
    //         }
    //     }
    // }
    void bfs(int i,int j,vector<vector<char>>&grid){
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>>que;
        grid[i][j]='0';
        que.push({i,j});
        while(!que.empty()){
            i=que.front().first;
            j=que.front().second;
            que.pop();
            for(auto it : dir){
            int i_=i+it[0];
            int j_=j+it[1];
            if(i_>=0&&i_<m&&j_>=0&&j_<n&&grid[i_][j_]=='1'){
                grid[i_][j_]=0;
                que.push({i_,j_});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    count++;
                    bfs(i,j,grid);
                }
            }
        }
        return count;
    }
};