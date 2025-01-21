class Solution {
public:
    int solve(vector<int>& nums,int idx,int ans,int sum,vector<vector<int>>&dp,int state){
        if(idx==nums.size()){
            if(ans==sum){
                return 1;
            }
            return 0;
        }
        if(dp[idx][sum+state]!=-1){
            return dp[idx][sum+state];
        }
        int plus=solve(nums,idx+1,ans,sum+nums[idx],dp,state);
        int minus=solve(nums,idx+1,ans,sum-nums[idx],dp,state);
        return dp[idx][sum+state]=(plus+minus);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int state=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(n,vector<int>(2*state+1,-1));
        return solve(nums,0,target,0,dp,state);
    }
};