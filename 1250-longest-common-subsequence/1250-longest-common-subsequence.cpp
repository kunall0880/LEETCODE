class Solution {
public:
    int solve(string &str1,string&str2,int idx1,int idx2,vector<vector<int>>&dp){
        if(idx1<0||idx2<0){
            return 0;
        }
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        if(str1[idx1]==str2[idx2]){
            return dp[idx1][idx2]=1+solve(str1,str2,idx1-1,idx2-1,dp);
        }
        return dp[idx1][idx2]=0+max(solve(str1,str2,idx1-1,idx2,dp),solve(str1,str2,idx1,idx2-1,dp));
    }
    int longestCommonSubsequence(string str1, string str2) {
        int l1=str1.length(),l2=str2.length();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,-1));
        return solve(str1,str2,l1-1,l2-1,dp);
    }
};