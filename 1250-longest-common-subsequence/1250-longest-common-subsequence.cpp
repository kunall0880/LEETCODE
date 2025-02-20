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

    // int l1=str1.length(),l2=str2.length();
    //     vector<int>prev(l2+1,0),curr(l2+1,0);
    //     prev[0]=0;
    //     for(int i=0;i<=l2;i++){
    //         prev[i]=0;
    //     }
    //     for(int i=1;i<=l1;i++){
    //         for(int j=1;j<=l2;j++){
    //             if(str1[i-1]==str2[j-1]){
    //                 curr[j]=1+prev[j-1];
    //             }else{
    //             curr[j]=max(prev[j],curr[j-1]);
    //             }
    //         }
    //         prev=curr;
    //     }
    //     return prev[l2];

    // int solve(string s1,string s2,int idx1,int idx2,vector<vector<int>>&dp){
    //     if(idx1<0||idx2<0){
    //         return 0;
    //     }
    //     if(dp[idx1][idx2]!=-1){
    //         return dp[idx1][idx2];
    //     }
    //     if(s1[idx1]==s2[idx2]){
    //         return dp[idx1][idx2]=1+solve(s1,s2,idx1-1,idx2-1,dp);
    //     }
    //     return dp[idx1][idx2]=0+max(solve(s1,s2,idx1-1,idx2,dp),solve(s1,s2,idx1,idx2-1,dp));
    // }
    int longestCommonSubsequence(string str1, string str2) {
        int l1=str1.length(),l2=str2.length();
        //vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
        vector<int>curr(l2+1,0),prev(l2+1,0);
        // for(int i=0;i<l1;i++){
        //     dp[i][0]=0;
        // }
        for(int i=0;i<l2;i++){
            prev[i]=0;
        }
        // return solve(str1,str2,l1-1,l2-1,dp);
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                if(str1[i-1]==str2[j-1]){
                    curr[j]=1+prev[j-1];
                }else{
                    curr[j]=max(curr[j-1],prev[j]);
                }
            }
            prev=curr;
        }
        return prev[l2];
    }
};