class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int l1=str1.length();
        int l2=str2.length();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,-1));
        for(int i=0;i<=l1;i++){
            for(int j=0;j<=l2;j++){
                if(i==0||j==0){
                    dp[i][j]=i+j;
                }else if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
                }
            }
        }
        string res="";
        int i=l1,j=l2;
        while(i>0&&j>0){
            if(str1[i-1]==str2[j-1]){
                res.push_back(str1[i-1]);
                i--;
                j--;
            }else{
                if(dp[i-1][j]<dp[i][j-1]){
                    res.push_back(str1[i-1]);
                    i--;
                }else{
                    res.push_back(str2[j-1]);
                    j--;
                }
            }
        }

        while(i>0){
            res.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            res.push_back(str2[j-1]);
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};