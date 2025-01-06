class Solution {
public:
    int minimumTotal(vector<vector<int>>& nums) {
        int m=nums.size(),n=nums[0].size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        //return sol(triangle,0,0,m,dp);
        for(int i=0;i<m;i++){
            dp[m-1][i]=nums[m-1][i];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                    int down=nums[i][j]+dp[i+1][j];
                    int dia=nums[i][j]+dp[i+1][j+1];
                    dp[i][j]=min(down,dia);
            }
        }
        return dp[0][0];
    }
};