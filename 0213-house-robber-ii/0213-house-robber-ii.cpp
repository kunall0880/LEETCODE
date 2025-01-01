class Solution {
public:
    int solve(vector<int>nums,int n,vector<int>&dp){
        if(n<0)return 0;
        if(n==0)return nums[n];
        if(dp[n]!=-1){
            return dp[n];
        }
        int take=nums[n]+solve(nums,(n-2),dp);
        int nottake=0+solve(nums,(n-1),dp);
        return dp[n]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        vector<int>temp1,temp2;
        int n=nums.size();
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        if(n==1)return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=n-1){
                temp2.push_back(nums[i]);
            }
        }
        return max(solve(temp1,n-2,dp1),solve(temp2,n-2,dp2));
    }
};