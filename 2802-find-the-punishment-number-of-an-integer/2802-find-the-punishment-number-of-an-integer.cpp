class Solution {
public:
    bool solve(int idx,string s,int sum,int num,vector<vector<int>>&dp){
        if(idx==s.length()){
            return sum==num;
        }
        if(sum>num){
            return false;
        }
        if(dp[idx][sum]!=-1){
            return dp[idx][sum];
        }
        bool ans=false;
        for(int j=idx;j<s.length();j++){
            string str=s.substr(idx,j-idx+1);
            int val=stoi(str);
            ans=ans||solve(j+1,s,sum+val,num,dp);
            if(ans){
                return dp[idx][sum]=ans;
            }
        }
        return dp[idx][sum]=ans;
    }
    int punishmentNumber(int n) {
        int sum=0;
        for(int i=1;i<=n;i++){
            int num=i*i;
            string str=to_string(num);
            vector<vector<int>>dp(str.length(),vector<int>(i+1,-1));
            if(solve(0,str,0,i,dp)){
                sum=sum+num;
            }
        }
        return sum;
    }
};