class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& nums) {
        int m=nums.size(),n=nums[0].size();
        if(m==1&&n==1){
            return nums[0][0];
        }
        long ans=INT_MAX;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            //dp[n-1][i]=nums[m-1][i];
            dp[0][i]=nums[0][i];
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                long long one=nums[i][j];
                if(j+1<n){
                    one+=dp[i-1][j+1];
                }else{
                    one=1e9;
                }
                long long two=nums[i][j]+dp[i-1][j];
                long long three=nums[i][j];
                if(j-1>=0){
                    three+=dp[i-1][j-1];
                }else{
                    three=1e9;
                }
                dp[i][j]=min({one,two,three});
            }
        }
        for(int i=0;i<n;i++){
            ans=min((int)ans,dp[n-1][i]);
        }
        return ans;
    }
};