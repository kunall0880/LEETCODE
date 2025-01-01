class Solution {
public:
    int ans(vector<int>nums,int n,vector<int>&dp){
        if(n<0)return 0;
        if(n==0)return nums[0];
        if(dp[n]!=-1){
            return dp[n];
        }
        int pick=nums[n]+ans(nums,n-2,dp);
        int notpick=0+ans(nums,n-1,dp);
        return dp[n]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(400,-1);
        return ans(nums,nums.size()-1,dp);
    }
};