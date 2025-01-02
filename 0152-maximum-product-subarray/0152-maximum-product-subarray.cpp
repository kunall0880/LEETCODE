class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int pre=1,suff=1,maxi=0;
        for(int i=0;i<n;i++){
            if(pre==0){
                pre=1;
            }
            if(suff==0){
                suff=1;
            }
            pre=pre*nums[i];
            suff=suff*nums[n-1-i];
            maxi=max(maxi,max(pre,suff));
        }
        return maxi;
    }
};