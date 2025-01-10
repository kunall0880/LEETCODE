class Solution {
public:
    int solve(vector<int>& nums,int amount,vector<vector<int>>&dp,int i){
        if(amount==0){
            return 1;
        }
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        if(nums[i]>amount){
            return dp[i][amount]=solve(nums,amount,dp,i+1);
        }
        int take=solve(nums,amount-nums[i],dp,i);
        int nottake=solve(nums,amount-0,dp,i+1);
        return dp[i][amount]=(take+nottake);
    }
    int change(int amount, vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(amount+1,-1));
        return solve(nums,amount,dp,0);
    }
};