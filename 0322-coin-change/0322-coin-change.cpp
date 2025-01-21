class Solution {
public:
    int coinChange(vector<int>& coins, int target) {
        int n=coins.size();
        vector<vector<long long>>dp(n,vector<long long>(target+1,0));
        //sort(coins.begin(),coins.end());
        for(int i=0;i<=target;i++){
            if(i%coins[0]==0){
                dp[0][i]=i/coins[0];
            }else{
                dp[0][i]=INT_MAX;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                long long nottake=0+dp[i-1][j];
                long long take=INT_MAX;
                if(coins[i]<=j){
                    take=1+dp[i][j-coins[i]];
                }
                dp[i][j]=min(take,nottake);
            }
        }
        return dp[n-1][target]==INT_MAX?-1:dp[n-1][target];
}
};