class Solution {
public:
    // void solve(int idx,vector<int>&nums,vector<int>&result,vector<int>&temp,int prev){
    //     if(idx>=nums.size()){
    //         if(temp.size()>result.size()){
    //             result=temp;
    //         }
    //         return ;
    //     }
    //     if(prev==-1||nums[idx]%prev==0){
    //         temp.push_back(nums[idx]);
    //         solve(idx+1,nums,result,temp,nums[idx]);
    //         temp.pop_back();
    //     }
    //     solve(idx+1,nums,result,temp,prev);
    // }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>prev(n,-1);
        int lastidx=0;
        int maxl=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[i]+1;
                        prev[i]=j;
                    }
                    if(dp[i]>maxl){
                        maxl=dp[i];
                        lastidx=i;
                    }
                }
            }
        }
        vector<int>ans;
        while(lastidx!=-1){
            ans.push_back(nums[lastidx]);
            lastidx=prev[lastidx];
        }
        return ans;
    }
};