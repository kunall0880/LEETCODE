class Solution {
public:
    int solve(vector<int>& coins,int idx,int sum,vector<vector<int>>&dp){
        if(idx==0){
            if(sum%coins[0]==0){
                return 1;
            }
            return 0;
        }
        if(dp[idx][sum]!=-1){
            return dp[idx][sum];
        }
        int nottake=solve(coins,idx-1,sum,dp);
        int take=0;
        if(sum>=coins[idx]){
            take=solve(coins,idx,sum-coins[idx],dp);
        }
        return dp[idx][sum]=(take+nottake);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(coins,n-1,amount,dp);
    }
};