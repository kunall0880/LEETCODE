class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        if((sum-target)%2!=0||(sum-target)<0){
            return 0;
        }
        sum=(sum-target)/2;
        vector<int>prev(sum+1,0),curr(sum+1,0);
        if(nums[0]==0){
            prev[0]=2;
        }else{
            prev[0]=1;
        }
        if(nums[0]!=0 && nums[0]<=sum){
            prev[nums[0]]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                int nottake=prev[j];
                int take=0;
                if(nums[i]<=j){
                    take=prev[j-nums[i]];
                }
                curr[j]=(take+nottake);
            }
            prev=curr;
        }
        return prev[sum];
    }
};