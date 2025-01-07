class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& nums) {
        int m=nums.size(),n=nums[0].size();
        if(m==1&&n==1){
            return nums[0][0];
        }
        long ans=INT_MAX;
        vector<int>prev(m,-1);
        for(int i=0;i<n;i++){
            //dp[n-1][i]=nums[m-1][i];
            prev[i]=nums[0][i];
        }
        for(int i=1;i<m;i++){
            vector<int>temp(n,-1);
            for(int j=0;j<n;j++){
                long long one=nums[i][j];
                if(j+1<n){
                    one+=prev[j+1];
                }else{
                    one=1e9;
                }
                long long two=nums[i][j]+prev[j];
                long long three=nums[i][j];
                if(j-1>=0){
                    three+=prev[j-1];
                }else{
                    three=1e9;
                }
                temp[j]=min({one,two,three});
            }
            prev=temp;
        }
        for(int i=0;i<n;i++){
            ans=min((int)ans,prev[i]);
        }
        return ans;
    }
};