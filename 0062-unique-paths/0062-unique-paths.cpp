class Solution {
public:
    int dynamic(int m,int n,vector<vector<long>>&dp){
        if(n==0 && m==0){
            return 1;
        }
        if(n<0 || m<0){
            return 0;
        }
        if( dp[m][n] != -1 ){
            return dp[m][n];
        }
        int u=dynamic(m-1,n,dp);
        int l=dynamic(m,n-1,dp);
        return dp[m][n]=(u+l);
    }
    int uniquePaths(int m, int n) {
        vector<vector<long>>dp(m+1,vector<long>(n+1,-1));
        return dynamic(m-1,n-1,dp);
    }
};