class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), s = 0;
        for (int i = 0; i < n; i++)
            s += nums[i];
        if (s % 2 != 0) {
            return false;
        }
        int target = (s / 2);
        vector<int> curr(target + 1, 0), prev(target + 1, 0);
        prev[0] = true;
        if (target >= nums[0]) {
            prev[nums[0]] = true;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                bool nottake = prev[j];
                bool take = false;
                if (j >= nums[i]) {
                    take = prev[j - nums[i]];
                }
                curr[j] = (take || nottake);
            }
            prev = curr;
        }
        return prev[target];
    }
    /*
        bool canPartition(vector<int>& nums) {
        int n=nums.size(),s=0;
        for(int i=0;i<n;i++)s+=nums[i];
        if(s%2!=0){
            return false;
        }
        int target=(s/2);
        vector<vector<bool>>dp(n+1,vector<bool>((s/2)+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(target>=nums[0]){
            dp[0][nums[0]]=true;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool nottake=dp[i-1][j];
                bool take=false;
                if(j>=nums[i]){
                take=dp[i-1][j-nums[i]];
                }
                dp[i][j]=(take||nottake);
            }
        }
        return dp[n-1][target];
    }



bool solve(vector<int> nums,int idx,int sum,vector<vector<int>>&dp){
        if(sum==0)return true;
        if(idx==0){
            if(idx==sum){
                return true;
            }
            return false;
        }
        if(dp[idx][sum]!=-1){
            return dp[idx][sum];
        }
        bool nottake=solve(nums,idx-1,sum,dp);
        bool take=false;
        if(sum>=nums[idx]){
            take=solve(nums,idx-1,sum-nums[idx],dp);
        }
        return dp[idx][sum]=(take || nottake);
    }



bool solve(vector<int>& nums,int idx,int sum){
        if(sum==0)return true;
        if(idx==0){
            if(idx==sum){
                return true;
            }
            return false;
        }
        bool nottake=solve(nums,idx-1,sum);
        bool take=false;
        if(sum>=nums[idx]){
            take=solve(nums,idx-1,sum-nums[idx]);
        }
        return (take || nottake);
    }
    */
};