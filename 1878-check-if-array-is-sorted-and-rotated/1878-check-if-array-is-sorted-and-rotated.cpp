class Solution {
public:
    bool check(vector<int>& nums) {
        int f=0,maxi=nums[0],n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                f++;
            }
        }
        if(nums[0]<nums[n-1]){
            f++;
        }
        if(f>1){
            return false;
        }
        return true;
    }
};