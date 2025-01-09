class Solution {
public:
    int solve(vector<int>& nums,int amount,vector<long long>&dp){
        if(amount<0){
            return INT_MAX;
        }
        if(amount==0){
            return 0;
        }
        if(dp[amount]!=-1){
            return dp[amount];
        }
        long long ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            long long count=INT_MAX;
            if(amount>=nums[i]){
                count=solve(nums,amount-nums[i],dp);
            }
            ans=min(ans,count+1);
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<long long>dp(amount+1,-1);
        long long ans=solve(coins,amount,dp);
        if(ans!=INT_MAX){
            return ans;
        }
        return -1;
    }
};