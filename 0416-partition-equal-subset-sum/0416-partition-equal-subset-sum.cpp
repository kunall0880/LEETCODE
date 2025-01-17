class Solution {
public:
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
};