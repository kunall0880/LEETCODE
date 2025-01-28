class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int BFS(int i,int j,vector<vector<int>>&grid){
        int m=grid.size(),n=grid[0].size();
        int count=0;
        queue<pair<int,int>>que;
        que.push({i,j});
        grid[i][j]=2;
        while(!que.empty()){
            i=que.front().first;
            j=que.front().second;
            que.pop();
            for(auto it : dir){
            int i_=i+it[0];
            int j_=j+it[1];
            if(i_>=0&&i_<m&&j_>=0&&j_<n&&grid[i_][j_]==1){
                que.push({i_,j_});
                grid[i_][j_]=2;
            }else if(i_>=0&&i_<m&&j_>=0&&j_<n&&grid[i_][j_]==2){

            }
            else {
                count++;
            }
        }
        }
        return count;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    count=BFS(i,j,grid);
                }
            }
        }
        return count;
    }
};