class Solution {
public:
    int minCostClimbingStairs(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        //return min(solve(nums,n,0,dp),solve(nums,n,1,dp));
        dp[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            int l=nums[i]+dp[i+1];
            int r=nums[i];
            if(i+2<n){
                r+=dp[i+2];
            }
            dp[i]=min(l,r);
        }
        for(int i=n-2;i>=1;i--){
            int l=nums[i]+dp[i+1];
            int r=nums[i];
            if(i+2<n){
                r+=dp[i+2];
            }
            dp[i]=min(l,min(dp[i],r));
        }
        return min(dp[1],dp[0]);
    }
};