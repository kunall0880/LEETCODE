class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    // int DFS(int i,int j,vector<vector<int>>&grid){
    //     int m=grid.size(),n=grid[0].size();
    //     int area=grid[i][j];
    //     grid[i][j]=0;
    //     for(auto it : dir){
    //         int i_=i+it[0];
    //         int j_=j+it[1];
    //         if(i_>=0&&i_<m&&j_>=0&&j_<n&&grid[i_][j_]==1){
    //             area+=DFS(i_,j_,grid);
    //         }
    //     }
    //     return area;
    // }
    int BFS(int i,int j,vector<vector<int>>&grid){
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>>que;
        int area=grid[i][j];
        que.push({i,j});
        grid[i][j]=0;
        while(!que.empty()){
            i=que.front().first;
            j=que.front().second;
            que.pop();
            for(auto it : dir){
            int i_=i+it[0];
            int j_=j+it[1];
            if(i_>=0&&i_<m&&j_>=0&&j_<n&&grid[i_][j_]==1){
                area+=grid[i_][j_];
                que.push({i_,j_});
                grid[i_][j_]=0;
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0,m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    area=max(area,BFS(i,j,grid));
                }
            }
        }
        return area;
    }
};