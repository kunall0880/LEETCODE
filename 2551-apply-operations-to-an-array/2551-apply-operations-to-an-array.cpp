class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]==nums[i]){
                nums[i-1]=nums[i-1]*2;
                nums[i]=0;
            }
        }
        int i=0;
        for(auto it :nums){
            if(it!=0){
                nums[i++]=it;
            }
        }
        while(i<nums.size()){
            nums[i++]=0;
        }
        return nums;
    }
};