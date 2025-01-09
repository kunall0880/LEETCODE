class Solution {
public:
    long long solve(vector<int>& nums,int n,int i,vector<long long>&dp){
        if(i>=n){
            return 0;
        }
        if(i==n-1){
            return nums[i];
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long l=nums[i]+solve(nums,n,i+1,dp);
        long long r=nums[i]+solve(nums,n,i+2,dp);
        return dp[i]=min(l,r);
    }
    int minCostClimbingStairs(vector<int>& nums) {
        int n=nums.size();
        vector<long long>dp(n,-1);
        return min(solve(nums,n,0,dp),solve(nums,n,1,dp));
    }
};