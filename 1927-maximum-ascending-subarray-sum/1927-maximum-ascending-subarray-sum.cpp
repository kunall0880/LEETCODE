class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int sum=nums[0];
        int maxsum=sum;
        for(int i=1;i<n;i++){
            if(nums[i-1]>=nums[i]){
                sum=nums[i];
            }else{
                sum=sum+nums[i];
                maxsum=max(maxsum,sum);
            }
        }
        return maxsum;
    }
};