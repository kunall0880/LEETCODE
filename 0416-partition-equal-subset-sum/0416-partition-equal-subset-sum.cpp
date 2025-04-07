class Solution {
public:
    int dp[201][20100];
    bool solve(vector<int>&nums,int ts,int idx){
        if(ts==0){
            return true;
        }
        if(idx>=nums.size()){
            return false;
        }
        if(dp[idx][ts]!=-1){
            return dp[idx][ts];
        }
        bool take=false;
        if(nums[idx]<=ts){
            take=solve(nums,ts-nums[idx],idx+1);
        }
        bool nottake=solve(nums,ts,idx+1);
        return dp[idx][ts]=(take||nottake);
    }
    bool canPartition(vector<int>& nums) {
        int val=accumulate(nums.begin(),nums.end(),0);
        if(val%2!=0){
            return false;
        }
        memset(dp,-1,sizeof(dp));
        return solve(nums,val/2,0);
    }
};