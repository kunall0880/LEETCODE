class Solution {
public:
    // int solve(string &str1,string&str2,int idx1,int idx2,vector<vector<int>>&dp){
    //     if(idx1<0||idx2<0){
    //         return 0;
    //     }
    //     if(dp[idx1][idx2]!=-1){
    //         return dp[idx1][idx2];
    //     }
    //     if(str1[idx1]==str2[idx2]){
    //         return dp[idx1][idx2]=1+solve(str1,str2,idx1-1,idx2-1,dp);
    //     }
    //     return dp[idx1][idx2]=0+max(solve(str1,str2,idx1-1,idx2,dp),solve(str1,str2,idx1,idx2-1,dp));
    // }
    int longestCommonSubsequence(string str1, string str2) {
        int l1=str1.length(),l2=str2.length();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
        for(int i=0;i<=l1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=l2;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[l1][l2];
    }
};