class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        //vector<vector<double>>dp(n,vector<double>(amount+1,0));
        vector<double>prev(amount+1,0),curr(amount+1,0);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
                prev[i]=1;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                double nottake=prev[j];
                double take=0;
                if(j>=coins[i]){
                    take=curr[j-coins[i]];
                }
                curr[j]=(take+nottake);
            }
            prev=curr;
        }
        return (int)prev[amount];
    }
};