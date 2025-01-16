class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,0)));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    dp[m-1][i][j]=grid[m-1][i];
                }else{
                    dp[m-1][i][j]=grid[m-1][i]+grid[m-1][j];
                }
            }
        }

        for(int i=m-2;i>=0;i--){
            for(int j1=0;j1<n;j1++){
                for(int j2=0;j2<n;j2++){
                    int maxi=-1e8;
                    for(int di=-1;di<=1;di++){
                        for(int dj=-1;dj<=1;dj++){
                            int ans=0;
                            if(j1==j2){
                                ans=grid[i][j1];
                            }else{
                                ans=grid[i][j1]+grid[i][j2];
                            }
                            if(j1+di<n && j1+di>=0 && j2+dj<n && j2+dj>=0){
                                ans+=dp[i+1][j1+di][j2+dj];
                            }else{
                                ans=-1e8;
                            }
                            maxi=max(ans,maxi);
                        }
                    }
                    dp[i][j1][j2]=maxi;
                }
            }
        }
        return dp[0][0][n-1];
    }
};