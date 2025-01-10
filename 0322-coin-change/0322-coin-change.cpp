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
    int coinChange(vector<int>& nums, int amount) {
        vector<long long>dp(amount+1,-1);
        int n=amount;
        dp[0]=0;
        for(int i=1;i<=n;i++){
            long long ans=INT_MAX;
            for(int j=0;j<nums.size();j++){
                long long count=INT_MAX;
                if(i-nums[j]>=0){
                    count=dp[i-nums[j]];
                }
                ans=min(ans,count+1);
            }
            dp[i]=ans;
        }
        if(dp[n]!=INT_MAX){
            return dp[n];
        }
        return -1;
    }
};