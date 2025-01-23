class Solution {
public:
    bool solve(vector<int>& piles,int idx,int r,int l,int &a,int &b,bool turn,vector<vector<int>>&dp){
        if(r>l){
            return 0;
        }
        if(dp[r][l]!=-1){
            return dp[r][l];
        }
        if(turn){
            a=max(piles[r]+solve(piles,idx,r+1,l,a,b,~turn,dp),piles[l]+solve(piles,idx,r,l-1,a,b,~turn,dp));
            dp[r][l]=a;
        }
        if(!turn){
            b=max(piles[r]+solve(piles,idx,r+1,l,a,b,~turn,dp),piles[l]+solve(piles,idx,r,l-1,a,b,~turn,dp));
            dp[r][l]=b;
        }
        return 0;
    }
    bool stoneGame(vector<int>& piles) {
        int a=0,b=0,n=piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        solve(piles,0,0,n-1,a,b,1,dp);
        if(a>b){
            return true;
        }
        return false;
    }
};