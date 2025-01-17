class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),s=0;
        for(int i=0;i<n;i++)s+=nums[i];
        if(s%2!=0){
            return false;
        }
        int target=(s/2);
        //vector<vector<bool>>dp(n+1,vector<bool>((s/2)+1,0));
        vector<int>curr(target+1,0),prev(target+1,0);
        prev[0]=true;
        if(target>=nums[0]){
            prev[nums[0]]=true;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool nottake=prev[j];
                bool take=false;
                if(j>=nums[i]){
                take=prev[j-nums[i]];
                }
                curr[j]=(take||nottake);
            }
            prev=curr;
        }
        return prev[target];
    }
};