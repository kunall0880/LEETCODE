class Solution {
public:
    int maxrow(vector<vector<int>>& grid,int n){
        int count=0;
        for(int i=0;i<grid[0].size();i++){
            if(grid[n][i]==1){
                count++;
            }
        }
        return count-1;
    }
    int maxcol(vector<vector<int>>& grid,int n){
        int count=0;
        for(int i=0;i<grid.size();i++){
            if(grid[i][n]==1){
                count++;
            }
        }
        return count-1;
    }
    int countServers(vector<vector<int>>& grid) {
        int maxi=-1e8;
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if((maxrow(grid,i)||maxcol(grid,j))){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};