class Solution {
public:
    int solve(vector<int>& nums,int idx,int ans,int sum,unordered_map<string,int>&dp){
        if(idx==nums.size()){
            if(ans==sum){
                return 1;
            }
            return 0;
        }
        string key=to_string(idx)+"_"+to_string(sum);
        if(dp.count(key)){
            return dp[key];
        }
        int plus=solve(nums,idx+1,ans,sum+nums[idx],dp);
        int minus=solve(nums,idx+1,ans,sum-nums[idx],dp);
        return dp[key]=(plus+minus);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<string,int>dp;
        return solve(nums,0,target,0,dp);
    }
};