class Solution {
public:
    int minPathSum(vector<vector<int>>& nums) {
        int m = nums.size(), n = nums[0].size();
        vector<vector<long>> dp(m, vector<long>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[0][0] = nums[0][0];
                }else {
                    long rig=nums[i][j];
                    if(j>0){
                        rig += dp[i][j - 1];
                    }else{
                        rig=INT_MAX;
                    }
                    long up=nums[i][j];
                    if(i>0){
                        up += dp[i - 1][j];
                    }else{
                        up=INT_MAX;
                    }
                    dp[i][j] = min(rig, up);
                }
            }
        }
        return (int)dp[m - 1][n - 1];
    }
};