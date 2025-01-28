class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
    int DFS(int i,int j,vector<vector<int>>&grid){
        int count=grid[i][j];
        grid[i][j]=0;
        int m=grid.size(),n=grid[0].size();
        for(auto it : dir){
            int i_=i+it[0];
            int j_=j+it[1];
            if(i_>=0&&i_<m&&j_>=0&&j_<n&&grid[i_][j_]!=0){
                count+=DFS(i_,j_,grid);
            }
        }
        return count;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    count=max(count,DFS(i,j,grid));
                }
            }
        }
        return count;
    }
};