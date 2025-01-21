class Solution {
public:
    int coinChange(vector<int>& coins, int target) {
        int n=coins.size();
        //vector<vector<long long>>dp(n,vector<long long>(target+1,0));
        //sort(coins.begin(),coins.end());
        vector<long long>prev(target+1,0);
        for(int i=0;i<=target;i++){
            if(i%coins[0]==0){
                prev[i]=i/coins[0];
            }else{
                prev[i]=INT_MAX;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                long long nottake=0+prev[j];
                long long take=INT_MAX;
                if(coins[i]<=j){
                    take=1+prev[j-coins[i]];
                }
                prev[j]=min(take,nottake);
            }
           // prev=curr;
        }
        return prev[target]==INT_MAX?-1:prev[target];
}
};