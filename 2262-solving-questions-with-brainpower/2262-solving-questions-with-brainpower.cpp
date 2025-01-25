class Solution {
public:
    long long solve(vector<vector<int>>& nums,int idx,int n,vector<long long>&dp){
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        long long nottake=0+solve(nums,idx+1,n,dp);
        long long take=nums[idx][0]+solve(nums,idx+nums[idx][1]+1,n,dp);
        return dp[idx]=max(nottake,take);
    }
    long long mostPoints(vector<vector<int>>& nums) {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i][0];
        }
        vector<long long>dp(n+1,-1);
        // for(int idx=n-1;idx>=0;idx--){
        //     long long nottake=0+dp[idx+1];
        //     long long take=0;
        //     if(idx+nums[idx][1]+1>=0){
        //         take=nums[idx][0]+dp[idx+nums[idx][1]+1];
        //     }
        //     dp[idx]=max(take,nottake);
        // }
        return solve(nums,0,n,dp);
    }
};