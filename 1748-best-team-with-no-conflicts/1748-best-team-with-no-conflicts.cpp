class Solution {
public:
    int solve(vector<pair<int,int>>&vec,vector<vector<int>>&dp,int n,int prev,int idx){
        if(idx==n){
            return 0;
        }
        if(dp[idx][prev+1]!=-1){
            return dp[idx][prev+1];
        }
        int pick=-1e8;
        if(prev==-1||vec[prev].second <= vec[idx].second){
            pick=vec[idx].second+solve(vec,dp,n,idx,idx+1);
        }
        int notpick=solve(vec,dp,n,prev,idx+1);
        return dp[idx][prev+1]=max(pick,notpick);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>>vec;
        int n=scores.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            vec.push_back({ages[i],scores[i]});
            maxi=max(maxi,ages[i]);
        }
        sort(vec.begin(),vec.end());
        vector<vector<int>>dp(1002,vector<int>(1002,-1));
        return solve(vec,dp,n,-1,0);
    }
};