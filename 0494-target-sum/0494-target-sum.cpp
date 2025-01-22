class Solution {
public:
    int solve(vector<int>& nums,int idx,int sum,vector<vector<int>>&dp){
        if(idx==0){
            if(sum==0 &&nums[0]==0){
                return 2;
            }
            if(sum==0||nums[idx]==sum){
                return 1;
            }
            return 0;
        }
        if(dp[idx][sum]!=-1){
            return dp[idx][sum];
        }
        int nottake=solve(nums,idx-1,sum,dp);
        int take=0;
        if(nums[idx]<=sum){
            take=solve(nums,idx-1,sum-nums[idx],dp);
        }
        return dp[idx][sum]=(take+nottake);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        if((sum-target)%2!=0||(sum-target)<0){
            return 0;
        }
        sum=sum-target;
        sum=sum/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(nums,n-1,sum,dp);
    }
};