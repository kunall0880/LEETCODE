class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int si=1,sd=1,msi=0,msd=0,n=nums.size();
        if(n==1){
            return n;
        }
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                si++;
                sd=1;
            }else if(nums[i-1]>nums[i]){
                si=1;
                sd++;
            }if(nums[i-1]==nums[i]){
                si=1;
                sd=1;
            }
            msd=max(msd,sd);
            msi=max(msi,si);
        }
        return max(msd,msi);
    }
};