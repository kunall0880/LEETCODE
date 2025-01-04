class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<long>>dp(m,vector<long>(n,-1));
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1){
            return 0;
        }
        if(m==1&&n==1){
            return m;
        }
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }else if(i==0 && j==0){
                    dp[i][j]=1;
                    continue;
                }else{
                    int u=0;
                    if(i>0){
                        u=dp[i-1][j];
                    }
                    int l=0;
                    if(j>0){
                        l=dp[i][j-1];
                    }
                    dp[i][j]=u+l;
                }
            }
        }
        return dp[m-1][n-1];
    }
};