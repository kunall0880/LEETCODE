class Solution {
public:
    int dynamic(int i,int j,vector<vector<long>>&dp){
        if(j==0 && i==0){
            return 1;
        }
        if(j<0 || i<0){
            return 0;
        }
        if( dp[i][j] != -1 ){
            return dp[i][j];
        }
        int u=dynamic(i-1,j,dp);
        int l=dynamic(i,j-1,dp);
        return dp[i][j]=(u+l);
    }
    int uniquePaths(int m, int n) {
        vector<vector<long>>dp(m+1,vector<long>(n+1,-1));
        //return dynamic(m-1,n-1,dp);
        if(m==1&&n==1){
            return m;
        }
        dp[0][0]=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int u=dp[i-1][j];
                int l=dp[i][j-1];
                dp[i][j]=(u+l);
            }
        }
        return -1*dp[m-1][n-1];
    }
};