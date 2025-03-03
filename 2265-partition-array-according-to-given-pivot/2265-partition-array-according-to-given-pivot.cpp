class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int less=0,equal=0,idx=0;
        int n=nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                less++;
                ans[idx]=nums[i];
                idx++;
            }else if(nums[i]==pivot){
                equal++;
            }
        }
        while(equal--){
            ans[idx]=pivot;
            idx++;
        }
        for(int i=0;i<n;i++){
            if(nums[i]>pivot){
                ans[idx]=nums[i];
                idx++;
            }
        }
        return ans;
    }
};