class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<long>>dp(m+1,vector<long>(n+1,-1));
        //vector<int>prev(n,-1);
        if(m==1&&n==1){
            return m;
        }
        //dp[0][0]=1;
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