class Solution {
public:
    // long long solve(vector<vector<int>>& nums,int idx,int n,vector<long long>&dp){
    //     if(idx>=n){
    //         return 0;
    //     }
    //     if(dp[idx]!=-1){
    //         return dp[idx];
    //     }
    //     long long nottake=0+solve(nums,idx+1,n,dp);
    //     long long take=nums[idx][0]+solve(nums,idx+nums[idx][1]+1,n,dp);
    //     return dp[idx]=max(nottake,take);
    // }
    long long mostPoints(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<long long>dp(2*n+1,0);
        for(int idx=n-1;idx>=0;idx--){
            long long nottake=0+dp[idx+1];
            long long take=nums[idx][0];
            if(idx+nums[idx][1]+1<n){
                take+=dp[idx+nums[idx][1]+1];
            }
            dp[idx]=max(take,nottake);
        }
        return dp[0];
    }
};