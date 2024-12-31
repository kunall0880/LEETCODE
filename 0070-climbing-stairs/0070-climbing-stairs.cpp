class Solution {
public:
    int dp[100];
    int solve(int n){
        if(n==0)return 1;
        if(n==1)return 1;
        if(dp[n]!=-1)return dp[n];
        int l = solve(n-1);
        int r = solve(n-2);
        return dp[n]=(l+r);
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};