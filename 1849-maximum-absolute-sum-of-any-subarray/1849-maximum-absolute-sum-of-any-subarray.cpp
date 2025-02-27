class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum1=0,sum2=0,n=nums.size(),maxi=INT_MIN;
        for(int i=0;i<n;i++){
            sum1+=nums[i];
            sum2+=nums[i];
            if(sum1<0){
                sum1=0;
            }
            if(sum2>0){
                sum2=0;
            }
            maxi=max(maxi,max(abs(sum1),abs(sum2)));
        }
        return maxi;
    }
};