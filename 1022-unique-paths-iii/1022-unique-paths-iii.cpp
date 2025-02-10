class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    void back(vector<vector<int>>& grid,int& res,int count,int total,int i,int j){
        int m=grid.size(),n=grid[0].size();
        if(i<0||i>=m||j<0||j>=n||grid[i][j]==-1){
            return;
        }
        if(grid[i][j]==2){
            if(count==total){
                res++;
            }
            return;
        }
        grid[i][j]=-1;
        for(auto & it : dir){
            int i_=i+it[0];
            int j_=j+it[1];
            back(grid,res,count+1,total,i_,j_);
        }
        grid[i][j]=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int i_=0,j_=0,count=1;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    i_=i;
                    j_=j;
                }else if(grid[i][j]==0){
                    count++;
                }
            }
        }
        int ans=0;
        back(grid,ans,0,count,i_,j_);
        return ans;
    }
};