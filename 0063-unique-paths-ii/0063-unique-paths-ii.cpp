class Solution {
public:
    int dynamic(int i,int j,vector<vector<long>>&dp,vector<vector<int>>nums){
        if((i>=0 && j>=0) && nums[i][j]==1){
            return 0;
        }
        if(j==0 && i==0){
            return 1;
        }
        if(j<0 || i<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int u=dynamic(i-1,j,dp,nums);
        int l=dynamic(i,j-1,dp,nums);
        return dp[i][j]=(u+l);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<long>>dp(m,vector<long>(n,-1));
        return dynamic(m-1,n-1,dp,obstacleGrid);
    }
};