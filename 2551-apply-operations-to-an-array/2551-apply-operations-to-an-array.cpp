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
        while(i<n){
            if(nums[i]==0){
                int j=i+1;
                while(j<n&&nums[j]==0){
                    j++;
                }
                if(i!=j&&i<j&&j<n){
                    swap(nums[i],nums[j]);
                }
            }
            i++;
        }
        return nums;
    }
};