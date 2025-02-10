class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        vector<int>ans;
        for(int i=0;i<=n;i++){
            dp[i][i]=1;
            dp[i][1]=i;
            dp[i][0]=1;
        }            
        for(int i=2;i<=n;i++){
            for(int j=2;j<=i;j++){
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<=n;i++){
            if(dp[n][i]==0){
                break;
            }
            ans.push_back(dp[n][i]);
        }
        return ans;
    }
};
/*
0 1 2  3 4 5 6
1 0 0  0 0 0 0   0
1 1 0  0 0 0 0   1
1 2 1  0 0 0 0   2
1 3 3  1 0 0 0   3
1 4 6  4 1 0 0   4
1 5 10 10 1 0   5
1 6 15 20 11 1  6
*/