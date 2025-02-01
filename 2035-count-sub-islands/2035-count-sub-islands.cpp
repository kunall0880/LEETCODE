class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    bool DFS(int i,int j,vector<vector<int>>& grid1, vector<vector<int>>& grid2,vector<vector<bool>>&visit){
        if(grid1[i][j]==0){
            return false;
        }
        visit[i][j]=true;
        bool ans=true;
        int m=grid2.size(),n=grid2[0].size();
        for(auto it : dir){
            int i_=i+it[0];
            int j_=j+it[1];
            if(i_>=0&&i_<m&&j_>=0&&j_<n&&grid2[i_][j_]==1&&!visit[i_][j_]){
                if(!DFS(i_,j_,grid1,grid2,visit)){
                    ans=false;
                }
            }
        }
        return ans;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid2.size(),n=grid2[0].size();
        int count=0;
        vector<vector<bool>>visit(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1&&!visit[i][j]){
                    if(DFS(i,j,grid1,grid2,visit)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};